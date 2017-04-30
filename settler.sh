#!/bin/bash

function echoCyan() {
    echo -e -n "\033[1;36m$1"
    echo -e -n '\033[0m\n'
}

clear
echoCyan "
==========================================================

███████╗███████╗████████╗████████╗██╗     ███████╗██████╗ 
██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔══██╗
███████╗█████╗     ██║      ██║   ██║     █████╗  ██████╔╝
╚════██║██╔══╝     ██║      ██║   ██║     ██╔══╝  ██╔══██╗
███████║███████╗   ██║      ██║   ███████╗███████╗██║  ██║
╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝

            Make any Ubuntu feel like home!
	 https://github.com/dulex123/backpack         
	

===========================================================
Press enter to settle.."

read



# === PPAs ===
echoCyan "Adding ppas"

echoCyan "7. Plank"
sudo add-apt-repository ppa:ricotz/docky -y

echoCyan "11. Atom"
sudo add-apt-repository ppa:webupd8team/atom -y

echoCyan "12. Numix"
sudo add-apt-repository ppa:numix/ppa -y

echoCyan "14. Albert"
sudo add-apt-repository ppa:nilarimogard/webupd8 -y

echoCyan "15. Ubuntu-make"
sudo add-apt-repository ppa:ubuntu-desktop/ubuntu-make -y

echoCyan "Apt-get update"
sudo apt-get update

# === Remove & Install ===

echoCyan "1. Remove libreoffice & ryhtmbox"
sudo apt-get -y remove --purge libreoffice* rhythmbox
sudo apt-get clean
sudo apt-get -y autoremove

echoCyan "2. Install wget"
sudo apt-get install wget -y

echoCyan "3. Get google chrome"
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb

echoCyan "4. Install google chrome"
sudo dpkg -i google-chrome-stable_current_amd64.deb

echoCyan "5. Install git"
sudo apt-get install git -y

echoCyan "6. Install vlc"
sudo apt-get install vlc -y

echoCyan "7. Install plank"
sudo apt-get install plank -y

echoCyan "8. Install php"
sudo apt-get install php -y

echoCyan "9. Install Jekyll"
sudo apt-get install jekyll -y

echoCyan "10. Install GIMP"
sudo apt-get install gimp -y

echoCyan "11. Install Atom editor"
sudo apt-get install atom -y

echoCyan "12. Install numix"
sudo apt-get install numix-gtk-theme numix-icon-theme-circle -y

echoCyan "13. Install virtualbox"
sudo apt-get install virtualbox -y

echoCyan "14. Install Albert"
sudo apt-get install albert -y


# === Clone dotfiles ===

echoCyan "Create bin in ~/"
mkdir ~/bin

echoCyan "Create dotfiles folder"
sh dotfiles.sh

echoCyan "Move templates"
cp -r backpack/templates/. ~/Templates/
