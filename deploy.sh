#!/bin/bash
echo "Uploading to Github..."
git add --all
git commit
git push
echo "Pi downloading and compiling code..."
ssh pi@192.168.0.51 '~/updategit.sh; ~/compile.sh'