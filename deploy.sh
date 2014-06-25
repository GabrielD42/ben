#!/bin/bash

if [ $# == 1 ]; then
	# color variables for output (see https://gist.github.com/GabrielD42/9de9668486ef0b642b48)
	green='\e[0;32m'
	NC='\e[0m' # No Color

	echo -e "\n${green}********************************\n* Uploading new code to Github *\n********************************${NC}\n"
	git add --all
	git commit -m $1
	git push
	echo -e "\n${green}*************************************\n* Pi downloading and compiling code *\n*************************************${NC}\n"
	ssh pi@192.168.0.51 '~/pullchanges.sh; make clean; make'
else
	echo "Please pass a commit message"
fi