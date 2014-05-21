#!/bin/bash

currenttime=$(date)
process=${0##*/}
action=$1

echo "At $currenttime $process $action" >> ben.log
echo >> ben.log

/usr/bin/mysql -u << eof
insert into log(time, process, action) values ("$currenttime", "$process", "$action")
eof

