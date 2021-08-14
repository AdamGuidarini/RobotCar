#ifndef CAR_H
#define CAR_H

#include <cstdint>
#include "motor.h"
#include "ultrasonic.h"
#include "pico/stdlib.h"

class Car
{
    private:
        Motor frontRight;
        Motor frontLeft;
        Motor backRight;
        Motor backLeft;
        Ultrasonic ultrasonic;
        uint64_t distance;

    public:
        Car(Motor front_right, Motor front_left, Motor back_right, Motor back_left, Ultrasonic ultrasonic_sensor);
        uint64_t getDistance();
        void forward();
        void reverse();
        void right();
        void left();
        void stop();
};

#endif