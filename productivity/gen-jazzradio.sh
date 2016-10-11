#!/bin/bash
AGENT="AudioAddict-di/1.4.7 iOS/8.1"
COOKIES="./cookies.txt"
AUTH="ephemeron:dayeiph0ne@pp"
DOMAIN=gmail.com
PLAYLISTDI="di.fm.m3u"
PLAYLISTSKY="sky.fm.m3u"
PLAYLISTJAZZ="jazzradio.m3u"
PLAYLISTROCK="rockradio.m3u"
JSONDI="http://listen.di.fm/premium_high.json"
JSONSKY="http://listen.sky.fm/premium_high.json"
JSONJAZZ="http://listen.jazzradio.com/premium_high.json"
JSONROCK="http://listen.rockradio.com/premium_high.json"

function rndsleep()
{
  sleep .$[ ( $RANDOM % 4 ) + 1 ]s
}

function playlist()
{
  playlistfile="$1"
  jsonurl="$2"
  radioname="$3"
  echo "#EXTM3U" > "$playlistfile"
  json=$(curl -s "$jsonurl")
  num=$(echo "$json" | jshon -l)
  for i in $(seq 0 $num); do
    name=$(echo $json | jshon -e $i -e name -u)
    playlist=$(echo $json | jshon -e $i -e playlist -u)
    echo "#EXTINF:0, $name" >> "$playlistfile"
    echo $playlist?$listen_key >> "$playlistfile"
  done
  echo "$radioname" playlist written to "$playlistfile"
}

# check for jshon
which jshon >/dev/null || (echo "install jshon first"; exit 1) || exit 1
# check for pwgen
which pwgen >/dev/null || (echo "install pwgen first"; exit 1) || exit 1
# check for curl
which curl >/dev/null || (echo "install curl first"; exit 1) || exit 1


# generate identity and password
login=$(pwgen -0 $[ ( $RANDOM % 2 ) + 6 ] 1 | tr [A-Z] [a-z])
lastname=$(pwgen -0 $[ ( $RANDOM % 4 ) + 8 ] 1 | tr [A-Z] [a-z])
pass=$(pwgen -0 $[ ( $RANDOM % 2 ) + 6 ] 1 | tr [A-Z] [a-z])

# register
curl -b $COOKIES -c $COOKIES -s -u $AUTH --request POST 'https://api.audioaddict.com/v1/di/members' --user-agent "$AGENT" \
--data-urlencode "member[first_name]=$login" --data-urlencode "member[last_name]=$lastname" \
--data-urlencode "member[password_confirmation]=$pass" --data-urlencode "member[password]=$pass" --data-urlencode "member[email]=$login@$DOMAIN" >/dev/null

rndsleep

# login
json=$(curl -b $COOKIES -c $COOKIES -s -u $AUTH --request POST "https://api.audioaddict.com/v1/di/members/authenticate" --user-agent "$AGENT" \
--data-urlencode "username=$login@$DOMAIN" --data-urlencode "password=$pass")

rndsleep

# set envs
api_key=$(echo "$json" | jshon -e api_key -u)
id=$(echo "$json" | jshon -e id -u)

rndsleep

# check premium avail for this acct.
curl -b $COOKIES -c $COOKIES -s -u $AUTH --request GET "https://api.audioaddict.com/v1/di/members/$id/subscriptions/trial_allowed/premium-pass?api_key=$api_key" \
 --user-agent "$AGENT" >/dev/null

rndsleep

# subscribe to 7 day premium trial
curl -b $COOKIES -c $COOKIES -s -u $AUTH --request POST "https://api.audioaddict.com/v1/di/members/8948397/subscriptions/trial/premium-pass" \
 --user-agent "$AGENT" --data-urlencode "api_key=$api_key" >/dev/null

rndsleep

#login again
json=$(curl -b $COOKIES -c $COOKIES -s -u $AUTH --request POST "https://api.audioaddict.com/v1/di/members/authenticate" --user-agent "$AGENT" \
--data-urlencode "username=$login@$DOMAIN" --data-urlencode "password=$pass")

# set envs
api_key=$(echo "$json" | jshon -e api_key -u)
listen_key=$(echo "$json" | jshon -e listen_key -u)
id=$(echo "$json" | jshon -e id)
activated=$(echo "$json" | jshon -e activated)

echo "activated $activated"
echo "listen_key $listen_key"
echo "api_key $api_key"
echo "id $id"
echo "login $login@$DOMAIN"
echo "password $pass"

# comment out these if you don't need playlists
#playlist "$PLAYLISTDI" "$JSONDI" di.fm
#playlist "$PLAYLISTSKY" "$JSONSKY" sky.fm
playlist "$PLAYLISTJAZZ" "$JSONJAZZ" jazzradio.com
#playlist "$PLAYLISTROCK" "$JSONROCK" rockradio.com
