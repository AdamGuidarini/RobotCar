#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
    private:
        uint8_t in_1;
        uint8_t in_2;
        int8_t direction;

    public:
        Motor();
        Motor(uint8_t in1, uint8_t in2);
        void setDirection(int8_t direction);
        void reverse();
        void stop();
        void forward();
};

#endif
