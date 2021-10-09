#include "ultrasonic.h"

/**
 * Default Constructor.
 */ 
Ultrasonic::Ultrasonic()
{
    trig = 0; echo = 0;
}

/**
 * Constructor for Ultrasonic class, calls pinSetup to initialize pins.
 * @param trigPin The pin on device connected to the trig pin on ultrasonic sensor.
 * @param echoPin The pin on device connected to the echo pin on ultrasonic sensor
 */
Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin)
{
    trig = trigPin;
    echo = echoPin;

    pinSetup();
}

/**
 * Initializes pins for trig and echo.
 */ 
void Ultrasonic::pinSetup()
{
    gpio_init(trig);
    gpio_init(echo);

    gpio_set_dir(trig, GPIO_OUT);
    gpio_set_dir(echo, GPIO_IN);
}

/**
 * Sends ultrasonic pulse and waits for response.
 * @return The time difference between when the pulse was sent and when pulse was received.
 */ 
uint64_t Ultrasonic::getPulse()
{
    uint64_t timeout = 26100;


    gpio_put(trig, 1);
    sleep_us(10);
    gpio_put(trig, 0);

    uint64_t duration = 0;

    while (gpio_get(echo) == 0)
    {
        tight_loop_contents();
    }

    absolute_time_t start = get_absolute_time();

    while (gpio_get(echo) == 1)
    {
        duration++;
        sleep_us(1);
        
        if (duration > timeout)
            return 0;
    }

    absolute_time_t end = get_absolute_time();

    return absolute_time_diff_us(start, end);
}

/**
 * Determines the distance between to item in front of ultrasonic sensor.
 * @return The distance to the object in front of the object.
 */ 
uint64_t Ultrasonic::getDistance()
{
    uint64_t pulseLength = getPulse();
    return pulseLength / 29 / 2;
}
