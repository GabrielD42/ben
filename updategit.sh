#!/bin/bash
cd ~/ben
git pull
cp * ~

# compile files
g++ -o ping ping.cpp