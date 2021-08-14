add_library(car car.h car.cpp)

target_link_libraries(car  pico_stdlib hardware_gpio motor ultrasonic)

target_include_directories(car PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")