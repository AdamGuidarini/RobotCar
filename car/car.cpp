#include "car.h"

Car::Car(Motor front_right, Motor front_left, Motor back_right, Motor back_left, Ultrasonic ultrasonic_sensor)
{
    frontRight = front_right;
    frontLeft = front_left;
    backRight = back_right;
    backLeft = back_left;
    ultrasonic = ultrasonic_sensor;
    distance = 0;
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
        distance = ultrasonic.getDistance();

        if (distance > stopDistance)
        {
            forward();
        }
        else
        {
            chooseDirection();
        }
    }
}
