# Docker cheatsheet
**This is madness, no this is docker!**

Dockerfile is used to build an image. Container is *started from image*. Changes during the life of container(s) *don't* affect the image.

[Awesome docker readme](https://github.com/wsargent/docker-cheat-sheet/blob/master/README.md)

[How to move default docker dir](https://linuxconfig.org/how-to-move-docker-s-default-var-lib-docker-to-another-directory-on-ubuntu-debian-linux)




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

Connect n terminals
```
	docker exec -it <container name> bash
```

## Container 

Fetch the whole container, like a snapshot of a regular VM. Saves the OS of course, but also any change you made, any data file written during the container life. This one is more like a traditional backup.

It will give you a flat .tar archive containing the filesystem of your container.

```
	docker export red_panda_container > latest.tar 
	# or
	docker export --output="latest.tar" red_panda_container
```



