add_executable(main main.cpp)

target_link_libraries(main car motor ultrasonic car pico_stdlib)

pico_enable_stdio_uart(main 0)
pico_enable_stdio_usb(main 1)

pico_add_extra_outputs(main)
