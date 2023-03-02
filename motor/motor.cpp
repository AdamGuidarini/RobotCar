#include "motor.h"
#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

/**
 * Default constructor.
 */ 
Motor::Motor()
{
    in_1 = 0;
    in_2 = 0;
}

/**
 * Constructor for Motor objects, takes pins for connection to motor as args
 *  and sets both to output.
 * @param in1 Pin number for forward motion.
 * @param in2 Pin number for reverse motion.
 */ 
Motor::Motor(uint8_t in1, uint8_t in2)
{
    in_1 = in1;
    in_2 = in2;

    gpio_init(in_1);
    gpio_init(in_2);

    gpio_set_dir(in_1, GPIO_OUT);
    gpio_set_dir(in_2, GPIO_OUT);
}

/**
 * Makes motor run in reverse.
 */ 
void Motor::reverse()
{
    gpio_put(in_1, 0);
    gpio_put(in_2, 1);
}

/**
 * Stops motor.
 */ 
void Motor::stop()
{
    gpio_put(in_1, 0);
    gpio_put(in_2, 0);
}

/**
 * Make motor run forward.
 */ 
void Motor::forward()
{
    gpio_put(in_1, 1);
    gpio_put(in_2, 0);
}

/**
 * Allows direction of the motor to be set.
 * @param direction Integer to determine direction
 *  -1: Reverse
 *   0: Stop
 *   1: Forward
 */ 
void Motor::setDirection(int8_t direction)
{
    switch (direction)
    {
        case -1:
            reverse();
            break;
        
        case 0:
            stop();
            break;
        
        case 1:
            forward();
            break;

        default:
            printf("%d is not a valid option.", direction);
            printf("Valid Options:\n");
            printf("-1: Reverse\n");
            printf(" 0: Stop\n");
            printf(" 1: Forward\n");
    }
}
