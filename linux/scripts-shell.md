# Linux shell scripts

## Alias scripts

Create bin folder for alias scripts and add it to PATH.

```sh
mkdir ~/bin
echo 'PATH+=:$HOME/bin' >> ~/.bashrc
mv "/path/to/spotlyrics.sh" ~/bin/spotlyrics && chmod +x ~/bin/spotlyrics
```
