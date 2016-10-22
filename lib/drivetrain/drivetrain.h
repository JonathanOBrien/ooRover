#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "wheel.h"
using namespace std;

class Drivetrain : public Wheel
{
  //Pin Definitions for the drivetrain
  //TODO: move this to a config file
  int BR1 = 22;
  int BR2 = 23;
  int BRPWM = 2;
  int FR1 = 24;
  int FR2 = 25;
  int FRPWM = 3;
  int BL1 = 26;
  int BL2 = 27;
  int BLPWM = 4;
  int FL1 = 28;
  int FL2 = 29;
  int FLPWM = 5;
  int STBY = 30;
  int STBY2 = 31;

    public:
        Drivetrain();
    private:
        void disableStandby();
};

#endif
