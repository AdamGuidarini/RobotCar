/**
 * Purpose - Creates an object for an ultrasonic sensor to use with rp2040 based devices.
 * SDK - pico-sdk: https://github.com/raspberrypi/pico-sdk
 * Programmer - Adam Guidarini
 * Inspired by - KleistRobotic's https://github.com/KleistRobotics/Pico-Ultrasonic
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>
#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "hardware/timer.h"

class Ultrasonic
{
    private:
        const uint64_t timeout = 26100;
        uint8_t trig;
        uint8_t echo;
        void pinSetup();
        uint64_t getPulse();
    
    public:
        Ultrasonic(uint8_t trigPin, uint8_t echoPin);
        uint64_t getDistance();
};

#endif 