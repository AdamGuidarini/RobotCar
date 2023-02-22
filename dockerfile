# our local base image
FROM ubuntu 

LABEL description="Container for use RobotCar for RaspberryPi Pico" 

# install build dependencies 
RUN apt-get update && apt-get install -y g++ rsync zip openssh-server make && apt install cmake -y

# install pico dependencies
RUN apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib -y
RUN apt install git -y && git clone https://github.com/raspberrypi/pico-sdk.git
RUN export PICO_SDK_PATH=/pico-sdk

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A 

# expose port 22 
EXPOSE 22