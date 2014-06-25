#!/bin/bash

# color variables for output (see https://gist.github.com/GabrielD42/9de9668486ef0b642b48)
red='\e[0;31m'
green='\e[0;32m'
NC='\e[0m' # No Color

usage() {
	echo -e "\n${red}Error: Incorrect Arguments.${NC}\n./deploy.sh [OPTION] 'commit message'\nWhere [OPTION] one of these flags:\n-g\tGabriel's Pi's IP Address\n-k\tKeane's Pi's IP Address\n-n\tDon't deploy code on a Pi\n"
	exit 1
	}

loginInfo=""
while getopts ":gkn" opt; do
	case $opt in
		g)
			loginInfo="pi@192.168.0.51"
			;;
		k)
			#insert ip address here
			;;
		n)
			#already left blank above. nothing to do here
			;;
		\?)
			usage
			;;
	esac
done

if [[ $# == 2 ]]; then
	echo -e "\n${green}********************************\n* Uploading new code to Github *\n********************************${NC}\n"
	git add --all
	git commit -m $1
	git push
	if [[ $loginInfo != "" ]]; then
		echo -e "\n${green}*************************************\n* Pi downloading and compiling code *\n*************************************${NC}\n"
		ssh $loginInfo '~/pullchanges.sh; make clean; make'
	fi
else
	usage
fi