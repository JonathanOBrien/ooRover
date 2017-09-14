#ifndef WHEEL_H
#define WHEEL_H
using namespace std;

class Wheel
{
    int direction;
    int speed;
    int lastNonZeroSpeed;
    char const * motorLocation;
    public:
        Wheel();
        void initalize(char const * location, char const * sideIN);
        void setDirection(int directionIn);
        void updateSpeed(int speedIn);
        void updateWheel(int speedIn);
        int getSpeed();

   private:
        void writeMotors();
};
#endif
