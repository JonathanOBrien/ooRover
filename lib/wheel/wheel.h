#ifndef WHEEL_H
#define WHEEL_H
using namespace std;

class Wheel
{
    int direction;
    int speed;
    int side;
    int signedSpeed;
    int lastNonZeroSpeed;
    char const * motorLocation;
    public:
        Wheel();
        void  initalize(char const * location, char const * sideIN);
        void  updateSpeed(int speedIn);
        void  testMode(int mode);
        int   getSpeed();

   private:
        void  writeMotor();
        int   normalizeSpeed(int speedIn);
        void  setDirection(int speedIn);
};
#endif
