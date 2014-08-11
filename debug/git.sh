#!/bin/bash

# color variables for output (see https://gist.github.com/GabrielD42/9de9668486ef0b642b48)
red='\e[0;31m'
green='\e[0;32m'
NC='\e[0m' # No Color

usage() {
	echo -e "\n${red}Error: Incorrect Arguments.${NC}\n./git.sh 'commit message'"
	exit 1
	}

if [[ $# == 1 ]]; then
	echo -e "\n${green}****************************\n* Generating documentation *\n****************************${NC}\n"
	doxygen doxygenConfig
	echo -e "\n${green}********************************\n* Uploading new code to Github *\n********************************${NC}\n"
	git add --all .
	git commit -m "$1"
	git push
else
	usage
fi