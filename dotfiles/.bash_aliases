#
# .bash_aliases file 
# for setTitle to work, in .bashrc 
# line PS1 needs to be commented out
#

#============
#Aliases
#============

alias gpom='git push origin master'
alias sagi='sudo apt-get install'
alias sagu='sudo apt-get update'
alias desk='cd ~/Desktop'
alias ..='cd ..'
alias ...='cd ../../../'
alias ....='cd../../../../'
alias projects='cd ~/Projects'
alias limundo='mogrify -resize 30% -format jpg *'
alias gacm='git add . && git commit -m'
alias gcm='git commit -m'
alias gacmp=gitAddCommitPushOriginMaster


#============
#Functions
#============

# For this to work you need to comment out  
# PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
# line in ~/.bashrc

setTitle() {
    echo -ne "\033]0;$1\007"
}

gitAddCommitPushOriginMaster() {
	gacm "$1"
	gpom
}

alias set-title=setTitle
