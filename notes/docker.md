# Docker cheatsheet
**This is madness, no this is docker!**

Dockerfile is used to build an image. Container is *started from image*. Changes during the life of container(s) *don't* affect the image.

(Awesome docker readme)[https://github.com/wsargent/docker-cheat-sheet/blob/master/README.md]


## Image

*May require sudo*

List all images
```
	docker images 
```

Save image as a file
```
	docker save -o <save image to path> <image name>
```

Load image from file
```
	docker load -i <path to image tar file>
```

## Container 

Fetch the whole container, like a snapshot of a regular VM. Saves the OS of course, but also any change you made, any data file written during the container life. This one is more like a traditional backup.

It will give you a flat .tar archive containing the filesystem of your container.

```
	docker export red_panda_container > latest.tar 
	# or
	docker export --output="latest.tar" red_panda_container
```



