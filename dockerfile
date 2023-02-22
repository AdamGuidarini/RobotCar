# our local base image
FROM ubuntu 

LABEL description="Container for use RobotCar for RaspberryPi Pico" 

# install pico dependencies
RUN set -ex;                                                                                            \
    apt-get update                                                                                      \
    apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib -y       \
    apt install git -y && git clone https://github.com/raspberrypi/pico-sdk.git                         \
    export PICO_SDK_PATH=/pico-sdk