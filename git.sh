#!/bin/bash
git add --all
git commit
git push
MESSAGE= git log -1 --pretty=%B
echo $MESSAGE
