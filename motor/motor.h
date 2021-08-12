#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class Motor
{
    private:
        uint8_t in_1;
        uint8_t in_2;
        int8_t direction;

    public:
        Motor(uint8_t in1, uint8_t in2);
        void setDirection(int8_t direction);
        void reverse();
        void stop();
        void forward();
};

#endif