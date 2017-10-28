# Tensorflow model building notes

### Reading data

Feed_dict will first send data from the storage system to the client, and then
from client to the worker process. This will cause the data to slow down, especially if the client is
on a different machine from the worker process. TensorFlow has readers that allow us to load
data directly into the worker process:

```
tf.TextLineReader
Outputs the lines of a file delimited by newlines
E.g. text files, CSV files

tf.FixedLengthRecordReader
Outputs the entire file when all files have same fixed lengths
E.g. each MNIST file has 28 x 28 pixels, CIFAR-10 32 x 32 x 3

tf.WholeFileReader
Outputs the entire file content

tf.TFRecordReader
Reads samples from TensorFlow's own binary format (TFRecord)

tf.ReaderBase
Allows you to create your own readers
```



### Tensors

-   `tf.constant()`
-   `tf.Variable(trainable=True/False)`
-   `tf.ones_like` - `tf.ones`
-   `tf.zeros_like` - `tf.zeros`
-   `tf.placeholder` - feed_dict - **Any tensors that are feedable can be fed (variables, ops, etc)!**

## Convolution

```python
tf.nn.conv2d(input, filter, strides, padding, use_cudnn_on_gpu=None, data_format=None, name=None)
```

Input: [Batch size x Height x Width x Channels]

Filter: [Height x Width x Input Channels x Output Channels ] (e.g . [5, 5, 3, 64])

Strides: 4 element 1-D tensor, strides in each direction of the input (often [1, 1, 1, 1] or [1, 2, 2, 1])

Padding: 'SAME' or 'VALID'

Data_format: String describing N, H, W, C



**Output size:** *(W−F+2P)/S+ 1*

*W: input width*
*F: filter width*
*P: padding*
*S: stride*



### Variable scope

-   The common practice is to create a variable scope for each layer. In variable scope, we don’t create variable using tf.Variable, but instead use tf.get_variable()

    ```python
    tf.get_variable(<name>, <shape>, <initializer>)
    ```

    If a variable with that name already exists in that variable scope, we use that variable. If a
    variable with that name doesn’t already exists in that variable scope, TensorFlow creates a new
    variable. Nodes in the same variable scope will be grouped together, and therefore you don’t have to use
    name scope any more. To declare a variable scope, you do it the same way you do name
    scope:

    ```python
    with tf.variable_scope('conv1') as scope:
    	w = tf.get_variable('weights', [5, 5, 1, 32])
    	b = tf.get_variable('biases', [32], initializer=tf.random_normal_initializer())
    	conv = tf.nn.conv2d(images, w, strides=[1, 1, 1, 1], padding='SAME')
    	conv1 = tf.nn.relu(conv + b, name=scope.name)
        
    with tf.variable_scope('conv2') as scope:
    	w = tf.get_variable('weights', [5, 5, 32, 64])
     	b = tf.get_variable('biases', [64], initializer=tf.random_normal_initializer())
     	conv = tf.nn.conv2d(conv1, w, strides=[1, 1, 1, 1], padding='SAME')
     	conv2 = tf.nn.relu(conv + b, name=scope.name)
    ```

    ​

### Randomization control for results reproduction

You often have to control the randomization process to get stable results for your experiments.
You’re probably familiar with random seed and random state from NumPy. TensorFlow doesn’t
allow to you to get random state the way numpy does (at least not that I know of -- I will double
check), but it does allow you to get stable results in randomization through two ways:

-    Set random seed at operation level. All random tensors allow you to pass in seed value in
    their initialization. For example:

    ```python
    my_var = tf.Variable(tf.truncated_normal((-1.0,1.0), stddev=0.1, seed=0))
    ```

    Note that, session is the thing that keeps track of random state, so each new session will start
    the random state all over again.

    ```python
    c = tf.random_uniform([], -10, 10, seed=2)

    with tf.Session() as sess:
    	print sess.run(c) # >> 3.57493
    	print sess.run(c) # >> -5.97319
        
    c = tf.random_uniform([], -10, 10, seed=2)

    with tf.Session() as sess:
    	print sess.run(c) # >> 3.57493
        
    with tf.Session() as sess:
    	print sess.run(c) # >> 3.57493
    ```

    With operation level random seed, each op keeps its own seed:

    ```python
    c = tf.random_uniform([], -10, 10, seed=2)
    d = tf.random_uniform([], -10, 10, seed=2)

    with tf.Session() as sess:
    	print sess.run(c) # >> 3.57493
    	print sess.run(d) # >> 3.57493
    ```

    ​

- Set random seed at graph level with tf.Graph.seed

    ```python
    tf.set_random_seed(seed)
    ```

    If you don’t care about the randomization for each op inside the graph, but just want to be able
    to replicate result on another graph (so that other people can replicate your results on their own
    graph), you can use tf.set_random_seed instead. Setting the current TensorFlow random seed
    affects the current default graph only.

    For example, you have two models a.py and b.py that have identical code:

    ```python
    import tensorflow as tf

    tf.set_random_seed(2)
    c = tf.random_uniform([], -10, 10)
    d = tf.random_uniform([], -10, 10)

    with tf.Session() as sess:
    	print sess.run(c)
    	print sess.run(d)
    ```

    ```shell
    $ python a.py
    >> -4.00752
    >> -2.98339
    $ python b.py
    >> -4.00752
    >> -2.98339
    ```

    ​


## Steps 

-   Assemble your graph

    1. Define placeholders for input and output
    2. Define the weights
    3. Define the inference model
    4. Define loss function
    5. Define optimizer

- Execute the computation

  Which is basically training your model. There are a few steps:

  1. Initialize all model variables for the first time.
  2. Feed in the training data. Might involve randomizing the order of data samples.
  3. Execute the inference model on the training data, so it calculates for each training input
     example the output with the current model parameters.
  4. Compute the cost
  5. Adjust the model parameters to minimize/maximize the cost depending on the model.



## Session

-   `tf.Session()`
-   `tf.InteractiveSession()` - use for development




### Saving weights

Saving weights with global step: (you should also save weights )

```python
self.global_step = tf.Variable(0, dtype=tf.int32, trainable=False, name='global_step')
self.optimizer = tf.train.GradientDescentOptimizer(self.lr).minimize(self.loss,
global_step=self.global_step)
saver = tf.train.Saver() # defaults to saving all variables
	with tf.Session() as sess:
 		sess.run(tf.global_variables_initializer())
 		average_loss = 0.0
 		writer = tf.summary.FileWriter('./improved_graph', sess.graph)
 		for index in xrange(num_train_steps):
 			batch = batch_gen.next()
 			loss_batch, _ = sess.run([model.loss, model.optimizer],
 			feed_dict={model.center_words: batch[0],
 			model.target_words: batch[1]})
 			average_loss += loss_batch
 			if (index + 1) % 1000 == 0:
 				saver.save(sess, 'checkpoints/skip-gram', global_step=model.global_step)
```

By default saver stores all variables of the graph and this is recommended. You can make a custom list of variables to store by passing them as dict or list:

```python
v1 = tf.Variable(..., name='v1')
v2 = tf.Variable(..., name='v2')

# pass the variables as a dict:
saver = tf.train.Saver({'v1': v1, 'v2': v2})

# pass them as a list
saver = tf.train.Saver([v1, v2])

# passing a list is equivalent to passing a dict with the variable op names # as keys
saver = tf.train.Saver({v.op.name: v for v in [v1, v2]})
```



Savers only save **graph variables**, so we need to create the graph ourselves and load in the variables. 

Restoring weights:

```python
saver.restore(sess, 'checkpoints/skip-gram-10000')
```



## Tensorboard

### Graph

```python
writer = tf.summary.FileWriter('./logs', sess.graph)
```

```shell
tensorboard --logdir='logs'
```

### Summaries

```python
def _create_summaries(self):
	with tf.name_scope("summaries"):
 		tf.summary.scalar("loss", self.loss
        tf.summary.scalar("accuracy", self.accuracy)
        tf.summary.histogram("histogram loss", self.loss)
        # because you have several summaries, we should merge them all
        # into one op to make it easier to manage
        self.summary_op = tf.summary.merge_all()
```

Because it’s an op, you have to execute it with sess.run()

```python
loss_batch, _, summary = sess.run([model.loss, model.optimizer, model.summary_op],
 feed_dict=feed_dict)
```

Now you’ve obtained the summary, you need to write the summary to file using the same
FileWriter object we created to visual our graph.

```python
writer.add_summary(summary, global_step=step)
```

You can visualize the statistics as images using tf.summary.image:

```python
tf.summary.image(name, tensor, max_outputs=3, collections=None)
```



## Gotchas

-   [`Trap of lazy loading`](http://danijar.com/structuring-your-tensorflow-models/)
-   ​