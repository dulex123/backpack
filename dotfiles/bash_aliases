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


#============
#Aliases
#============

alias gpom='git push origin master'
alias sagi='sudo apt-get install'
alias sagu='sudo apt-get update'
alias saar='sudo add-apt-repository'
alias ..='cd ..'
alias ...='cd ../../../'
alias ....='cd../../../../'
alias limundo='mogrify -resize 30% -format jpg *'
alias gacm='git add . && git commit -m'
alias gcm='git commit -m'
alias gacmp=gitAddCommitPushOriginMaster

# Locations
alias desk='cd ~/Desktop'
alias lab='cd ~/Desktop/lab'
alias data='cd ~/Desktop/data'
alias flow='cd ~/Desktop/flow'

# IP
ipa="dig +short myip.opendns.com @resolver1.opendns.com"
lipa=""

#Docker
alias dls='docker ps'
alias dlsa="docker ps -a --format 'table {{ .ID }}\t{{ .Names }}\t{{ .Ports }}\t{{ .Image}}' "
#dlsa --format 'table {{ .ID }}\t{{ .Names }}\t{{ .Ports }}\t{{ .Image}}' #asdfasdfasfd
alias ds='docker start'
alias da='docker attach'
alias drn='docker rename'
alias drm='docker rm'
alias drmi='docker rmi'


alias stt=setTitle
