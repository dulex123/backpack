# README Boilerplate

## Example usage
Video/GIF/Code that showcases the usage of the package. In the ideal case, people should be able to infer from your example how your library works.

## Logitech k811
[Use this to remap RSHIFT to UP on Ubuntu 20.04](http://www.fascinatingcaptain.com/projects/remap-keyboard-keys-for-ubuntu/)  
[Use this to remap EJECT to DELETE](https://askubuntu.com/questions/1019276/fake-key-code-for-remapped-keyboard-keys/1019659#1019659)  
```bash
# Remap EJECT to DELETE for Logitech k811
echo "evdev:input:b0005v046DpB317e0900*
 KEYBOARD_KEY_c00b8=delete" | sudo tee /etc/udev/hwdb.d/65-keyboard-custom.hwdb
 
sudo systemd-hwdb update
sudo udevadm trigger
```

## Installation

Download to your project directory, add it, and commit.

```sh
curl -O https://github.com/christianbundy/readme-boilerplate.md
git add README.md
git commit -m "Add README Boilerplate"
```

## Usage

Edit `README.md` with the name of your project, a description, installation instructions, usage instructions, how to get support, and how people can contribute to your project.

## Support

none, nada, aucune...

## Contributing

Fork the project, create a new branch, make your changes, and open a pull request.

We use [Clear code](http://introcs.cs.princeton.edu/java/11style/) writing guidelines.
This tool can convert nicely to pdf [MarkdownToPdf](http://www.markdowntopdf.com/)

# Credits

Released under the [MIT License].<br>
Authored and maintained by Dušan Josipović.

> Blog [dulex123.github.io](http://dulex123.github.io) &nbsp;&middot;&nbsp;
> GitHub [@dulex123](https://github.com/dulex123) &nbsp;&middot;&nbsp;
> Twitter [@josipovicd](https://twitter.com/josipovicd)

[MIT License]: http://mit-license.org/
