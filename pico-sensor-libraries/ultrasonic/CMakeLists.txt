add_library(rp2040_ultrasonic ultrasonic.h ultrasonic.cpp)

target_link_libraries(rp2040_ultrasonic  pico_stdlib hardware_gpio hardware_timer)

target_include_directories(rp2040_ultrasonic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")