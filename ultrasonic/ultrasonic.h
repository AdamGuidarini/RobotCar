/**
 * Purpose - Creates an object for an ultrasonic sensor to use with rp2040 based devices.
 * SDK - pico-sdk: https://github.com/raspberrypi/pico-sdk
 * Programmer - Adam Guidarini
 * Inspired by - KleistRobotic's https://github.com/KleistRobotics/Pico-Ultrasonic
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

class Ultrasonic
{
    private:
        uint8_t trig;
        uint8_t echo;
        void pinSetup();
        uint64_t getPulse();
    
    public:
        Ultrasonic();
        Ultrasonic(uint8_t trigPin, uint8_t echoPin);
        uint64_t getDistance();
};

#endif 
