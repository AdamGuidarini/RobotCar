#include "car.h"

Car::Car(Motor front_right, Motor front_left, Motor back_right, Motor back_left, Ultrasonic ultrasonic_sensor)
{
    frontRight = front_right;
    frontLeft = front_left;
    backRight = back_right;
    backLeft = back_left;
    ultrasonic = ultrasonic_sensor;
}


uint64_t Car::getDistance()
{
    uint8_t measurments = 5;
    uint64_t sum;

    for (int i = 0; i < measurments; i++)
    {
        sum += ultrasonic.getDistance();
        sleep_us(500);
    }

    return sum / measurments;
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

void Car::forward()
{
    frontRight.setDirection(1);
    backRight.setDirection(1);

    frontLeft.setDirection(-1);
    backLeft.setDirection(-1);
}

void Car::reverse()
{
    frontRight.setDirection(-1);
    backRight.setDirection(-1);

    frontLeft.setDirection(1);
    backLeft.setDirection(1); 
}

void Car::stop()
{
    frontRight.setDirection(0);
    frontLeft.setDirection(0);
    backRight.setDirection(0);
    backLeft.setDirection(0);
}
