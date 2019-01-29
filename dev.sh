#!/bin/bash

#nodemon --watch src -e cpp --exec ./dev.sh

lsof -i -P | grep -i "main" | grep -i "11000" | awk '{print $2}' | xargs kill
cd ./cmake-build-debug
make -j8
./src/main
