#!/bin/bash

# color variables for output (see https://gist.github.com/GabrielD42/9de9668486ef0b642b48)
green='\e[0;32m'
NC='\e[0m' # No Color

echo -e "${green}Uploading to Github...${NC}"
git add --all
git commit
git push
echo -e "${green}Pi downloading and compiling code...${NC}"
ssh pi@192.168.0.51 '~/pullchanges.sh; ~/compile.sh'