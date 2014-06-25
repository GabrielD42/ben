#!/bin/bash

# color variables for output (see https://gist.github.com/GabrielD42/9de9668486ef0b642b48)
green='\e[0;32m'
NC='\e[0m' # No Color

usage() {
	echo -e "Error: Incorrect Arguments.\n./deploy.sh [OPTION] 'commit message'\nWhere [OPTION] is either:\n-g\tGabriel's Pi's IP Address\n-k\tKeane's Pi's IP Address"
	}

$login = ""
while getopts ":gk" opt; do
	case $opt in
		g)
			$login = "pi@192.168.0.51"
			;;
		k)
			#insert ip address here
			;;
		\?)
			usage
			;;
	esac
done

if [ $# == 2 ]; then
	echo -e "\n${green}********************************\n* Uploading new code to Github *\n********************************${NC}\n"
	git add --all
	git commit -m $1
	git push
	echo -e "\n${green}*************************************\n* Pi downloading and compiling code *\n*************************************${NC}\n"
	if [[ $login != "" ]]; then
		ssh $login '~/pullchanges.sh; make clean; make'
	fi
else
	usage
fi