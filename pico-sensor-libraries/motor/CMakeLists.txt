add_library(rp2040_motor motor.h motor.cpp)

target_link_libraries(rp2040_motor  pico_stdlib hardware_gpio hardware_timer)

target_include_directories(rp2040_motor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")