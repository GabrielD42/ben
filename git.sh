#!/bin/bash
git add --all
git commit
git push
MESSAGE = git log -1 --pretty=%B
echo $MESSAGE
ssh ben42picow@gabriel-damon.com "wp post create $MESSAGE --post_title='git push' --post_status=publish"
