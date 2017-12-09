#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "wheel.h"
#include "ArduinoMegaPins.h"
#include "InitSystem.h"
#include "SystemClock.h"
using namespace std;

class Drivetrain : public Wheel
{
  //Create wheel objects for 4 wheels
  Wheel FR;
  Wheel FL;
  Wheel BR;
  Wheel BL;

//speed and heading variables
  int heading;
  int speed;
  int minIncrement;

    public:
        Drivetrain();
        void stop();
        void turnLeft();
        void turnRight();
        void updateSpeed(int speed);
        void testBR(int in);
        void testBL(int in);
        void testFL(int in);
        void testFR(int in);
        int getMI();

    private:
        void disableStandby();
        int calcDelta(int speedIn, int operation);
};

#endif
