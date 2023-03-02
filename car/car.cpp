#include "car.h"
#include "pico/stdlib.h"

Car::Car(Motor front_right, Motor front_left, Motor back_right, Motor back_left, Ultrasonic ultrasonic_sensor)
{
    frontRight = front_right;
    frontLeft = front_left;
    backRight = back_right;
    backLeft = back_left;
    ultrasonic = ultrasonic_sensor;
    distance = 0;

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
}

void Car::forward()
{
    frontRight.setDirection(-1);
    backRight.setDirection(-1);

    frontLeft.setDirection(1);
    backLeft.setDirection(1); 
}

void Car::reverse()
{
    frontRight.setDirection(1);
    backRight.setDirection(1);

    frontLeft.setDirection(-1);
    backLeft.setDirection(-1);
}

void Car::right()
{
    frontRight.setDirection(1);
    frontLeft.setDirection(1);
    backRight.setDirection(1);
    backLeft.setDirection(1);
}

void Car::left()
{
    frontRight.setDirection(-1);
    frontLeft.setDirection(-1);
    backRight.setDirection(-1);
    backLeft.setDirection(-1);
}

void Car::stop()
{
    frontRight.setDirection(0);
    frontLeft.setDirection(0);
    backRight.setDirection(0);
    backLeft.setDirection(0);
}

void Car::chooseDirection()
{
    const uint32_t turnTime = 350;
    uint16_t multiplier = 1;
    uint64_t distLeft;
    uint64_t distRight;

    while (true)
    {
        left();
        sleep_ms(turnTime * multiplier);

        stop();

        distLeft = ultrasonic.getDistance();

        right();
        sleep_ms(turnTime * multiplier * 2);

        stop();

        if (distLeft > stopDistance && distLeft >= distRight)
        {
            left();
            sleep_ms(turnTime * multiplier * 2);
            break;
        }
        else if (distRight > stopDistance && distRight > distLeft)
        {
            break;
        }
        else
            multiplier++;
    }
}

void Car::drive()
{
    while(true)
    {
        uint32_t delayTime = motorPulseDelay();
        distance = ultrasonic.getDistance();

        distance > stopDistance ? forward() : chooseDirection();

        if (delayTime > 0) 
        {
            gpio_put(25, 1);
            busy_wait_us(delayTime * 2);

            stop();

            gpio_put(25, 0);
            // busy_wait_us(delayTime );
        }
    }
}

int Car::motorPulseDelay()
{
    if (distance >= 450)
        return 0;
    else if (distance >= 300)
        return 5;
    else if (distance >= 200)
        return 10;
    else if (distance >= 100)
        return 15;

    return 20;
}
 