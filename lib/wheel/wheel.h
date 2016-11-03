#ifndef WHEEL_H
#define WHEEL_H
using namespace std;

class Wheel
{
    int direction;
    int speed;
    int PWM;
    int IN1;
    int IN2;
    int side;
    public:
        Wheel();
        void initalize(int input1, int input2, int pwmIN, char const * sideIN);
        void setDirection(char const * directionIn, int speedIn);
        void updateSpeed(int speedIn);
        int getSpeed();

   private:
        void writeMotors();
};
#endif
