add_library(ultrasonic ultrasonic.h ultrasonic.cpp)

target_link_libraries(ultrasonic pico_stdlib hardware_gpio hardware_timer)

target_include_directories(ultrasonic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")