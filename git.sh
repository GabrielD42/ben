#!/bin/bash
git add --all
git commit
git push

BRANCH=$(git rev-parse --abbrev-ref HEAD)
MESSAGE=$(git log -1 --pretty=%B)
ssh ben42picow@gabriel-damon.com "./wp-cli.phar post create --post_content='$MESSAGE' --post_title='git push origin $BRANCH' --post_status=publish --path='public_html/ben/'"
