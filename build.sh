#!/bin/bash

sudo docker build -t ubuntu-pico .
sudo docker run -p 5000:22 -i -t ubuntu-pico /bin/bash

mkdir build
