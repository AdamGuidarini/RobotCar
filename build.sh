#!/bin/bash

# build build directory
if [ ! -d build ]; then
    mkdir build
fi

# build container if not exists
if [ "$(docker images -q ubuntu-pico 2> /dev/null)" = "" ]; then
    echo "Building docker container"
    sudo docker build -t ubuntu-pico -f dockerfile . || exit 1
fi

# Run container and compile program
sudo docker run -u root                                          \
    --privileged=true                                       \
    --entrypoint=/bin/bash                                  \
    --rm -i                                                 \
    --mount type=bind,source="$(pwd)",target=/root/RobotCar \
    ubuntu-pico << COMMANDS
    cd /root/RobotCar/build;
    cmake ..;
    make -j$(nproc);
COMMANDS

if [[ -d "/run/media/$(whoami)/RPI-RP2" ]]; then
    echo "Flashing program to Pico...";
    cp build/elf2uf2/elf2uf2 /run/media/$(whoami)/RPI-RP2;
    echo "done!"
fi