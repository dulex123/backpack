#!/bin/bash
function echoRed() {
	echo -e "\033[31m $1"
}

echoRed "Adding ppas"

echoRed "7. Plank"
sudo add-apt-repository ppa:ricotz/docky

echoRed "11. Atom"
sudo add-apt-repository ppa:webupd8team/atom

echoRed "12. Numix"
sudo add-apt-repository ppa:numix/ppa

echoRed "14. Albert"
sudo add-apt-repository ppa:nilarimogard/webupd8

echoRed "15. Ubuntu-make"
sudo add-apt-repository ppa:ubuntu-desktop/ubuntu-make

echoRed "Apt-get update"
sudo apt-get update

echoRed "1. Remove libreoffice & ryhtmbox"
sudo apt-get -y remove --purge libreoffice* rhythmbox
sudo apt-get clean
sudo apt-get -y autoremove

echoRed "2. Install wget"
sudo apt-get install wget

echoRed "3. Get google chrome"
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb

echoRed "4. Install google chrome"
sudo dpkg -i google-chrome-stable_current_amd64.deb

echoRed "5. Install git"
sudo apt-get install git

echoRed "6. Install vlc"
sudo apt-get install vlc

echoRed "7. Install plank"
sudo apt-get install plank

echoRed "8. Install php"
sudo apt-get install php

echoRed "9. Install Jekyll"
sudo apt-get install jekyll

echoRed "10. Install GIMP"
sudo apt-get install gimp

echoRed "11. Install Atom editor"
sudo apt-get install atom

echoRed "12. Install numix"
sudo apt-get install numix-gtk-theme numix-icon-theme-circle

echoRed "13. Install virtualbox"
sudo apt-get install virtualbox

echoRed "14. Install Albert"
sudo apt-get install albert

echoRed "15. Install umake"
sudo apt-get install ubuntu-make

echoRed "16. Install pychram"
umake ide pycharm-professional

echoRed "17. Install Clion"
umake ide clion

echoRed "Create bin in ~/"
mkdir ~/bin

echoRed "Move dotifles"
git clone https://github.pcom/dulex123/backpack
cp -r backpack/dotfiles/. ~/

echoRed "Move templates"
cp -r backpack/templates/. ~/Templates/

