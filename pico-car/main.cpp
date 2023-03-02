#include <cstdint>
#include "pico/stdlib.h"
#include "motor.h"
#include "ultrasonic.h"
#include "hardware/uart.h"
#include "car.h"


int main()
{
    sleep_ms(500);

    Motor fLeft(16, 17);
    Motor fRight(20, 21);
    Motor bLeft(18, 19);
    Motor bRight(22, 26);
    Ultrasonic ultrasonic(5, 4);

    Car car(fRight, fLeft, bRight, bLeft, ultrasonic);

    car.drive();

    return 0;
}
