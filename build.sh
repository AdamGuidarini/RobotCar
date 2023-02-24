#!/bin/bash

# build build directory
if [ ! -d build ]; then
    mkdir build
fi

# build container if not exists
if [ "$(docker images -q ubuntu-pico 2> /dev/null)" = "" ]; then
    docker build -t ubuntu-pico -f dockerfile . || exit 1
fi
docker run -p 5000:22 -it ubuntu-pico /bin/bash