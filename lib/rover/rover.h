#ifndef ROVER_H
#define ROVER_H
using namespace std;
#include "drivetrain.h"
#include "HMC5883L.h"

class Rover : public Drivetrain, public HMC5883L
{
  HMC5883L compass;
  Drivetrain drivetrain;
  int desiredSpeed;
  int desiredHeading;

    public:
        Rover();
        void run();
        void autoPilot();
        void manual();
        void setHeading(int headingIn);
        void setSpeed(int speedIn);
        void serviceMode();
    private:
        void alterCourse();
};

#endif
