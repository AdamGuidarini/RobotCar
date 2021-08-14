add_library(motor motor.h motor.cpp)

target_link_libraries(motor  pico_stdlib hardware_gpio hardware_timer)

target_include_directories(motor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")