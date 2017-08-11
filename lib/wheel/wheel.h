#ifndef WHEEL_H
#define WHEEL_H
using namespace std;

class Wheel
{
    int direction;
    int speed;
    char const * motorLocation;
    public:
        Wheel();
        void initalize(char const * location, char const * sideIN);
        void setDirection(char const * directionIn, int speedIn);
        void updateSpeed(int speedIn);
        int getSpeed();

   private:
        void writeMotors();
};
#endif
