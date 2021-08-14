cmake_minimum_required(VERSION 3.13.0)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(robo-car)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_DIR .)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# The rest
add_subdirectory(motor)
add_subdirectory(ultrasonic)
add_subdirectory(car)
add_subdirectory(pico-car)
