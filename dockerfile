FROM ubuntu:latest

LABEL description="Container for use RobotCar for RaspberryPi Pico"

# Install dependencies
RUN set -ex;                                                                                                   \
    apt-get update;                                                                                            \
    apt install cmake g++ gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib python3 -y; \
    cd $HOME;                                                                                                  \
    apt install git -y;                                                                                        \
    git clone https://github.com/raspberrypi/pico-sdk.git;                                                     \
    echo "PICO_SDK_PATH='$HOME/pico-sdk'" >> $HOME/.bashrc;