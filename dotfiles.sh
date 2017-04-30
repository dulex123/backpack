#!/bin/bash
dir=~/dotfiles
olddir=~/old_dotfiles

# dotfiles_old in homedir
echo "Creating $olddir for backup of any existing dotfiles in ~/"
mkdir -p $olddir

echo "Creating $dir"
mkdir -p $dir

cp -r dotfiles ~/
for file in $(ls ~/dotfiles/)
do
    cp ~/.$file ~/$olddir/$file 2> /dev/null
    rm -rf ~/.$file        
    ln -s ~/dotfiles/$file ~/.$file
done
