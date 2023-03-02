#ifndef CAR_H
#define CAR_H

#include <cstdint>
#include "motor.h"
#include "ultrasonic.h"

class Car
{
    private:
        const uint8_t stopDistance = 15;
        Motor frontRight;
        Motor frontLeft;
        Motor backRight;
        Motor backLeft;
        Ultrasonic ultrasonic;
        unsigned short distance;
        void forward();
        void reverse();
        void right();
        void left();
        void stop();
        void stop_us(uint32_t stopTime);
        void chooseDirection();
        int motorPulseDelay();

    public:
        Car(Motor front_right, Motor front_left, Motor back_right, Motor back_left, Ultrasonic ultrasonic_sensor);
        void drive();
};

#endif