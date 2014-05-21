#!/bin/bash

oldip=$(cat ipaddress)
newip=$(/sbin/ifconfig eth0 | awk '/inet addr:/ {print $2}' | awk -F: '{print $2}')
echo "$newip" > ipaddress

if [ "$newip" != "$oldip" ]; then
./log.sh "uploaded Pi's new IP address, $newip, to members.cruzio.com/~laovel/ipaddress"

HOST='gabriel-damon.com'
USER='admin@gabriel-damon.com'
PASSWD=$(more password)

ftp -n -v $HOST << EOT
ascii
user $USER $PASSWD
prompt
delete ipaddress
put ipaddress
bye
EOT
fi
