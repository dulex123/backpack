# Python cheatsheet

## Dictionaries
```python
# Used when you need lookup table with unique keys
europe = {'spain':'madrid', 'france':'paris', 'germany':'berlin'}
europe.keys()           # returns spain,france,germany

# Keys have to be immutable, list cannot be a key

del(europe['spain'])    # removes key-value pair for key spain
'spain' in europe       # asserts if key is inside dict (boolean)

# With nested dictionaries chain rule applies for data retrieval
europe = {
    'spain': {'capital':'madrid', 'population':46.77},
    'france': {'capital':'rome', 'population':66.03} }

print(europe['spain']['capital'])   # returns madrid

```

## Accessing variables