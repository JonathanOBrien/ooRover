#include "drivetrain.h"
#include "wheel.h"
#include <ioPins.h>
#include "ArduinoMegaPins.h"
#include "InitSystem.h"
#include "SystemClock.h"
using namespace std;

Drivetrain :: Drivetrain(){
  //create wheels for the drivetrain
  //TODO: this needs to support more vehicle types
  //TODO: modular based on number of wheels
  FR.initalize("FR","right");
  FL.initalize("FL","left");
  BR.initalize("BR","right");
  BL.initalize("BL","left");
  //prepare motors for use
  //Set the standby pins for use
  setGpioPinModeOutput(STBY);
  setGpioPinModeOutput(STBY2);
  //turn off standby on both speed controllers
  disableStandby();
  }
void Drivetrain :: disableStandby(){
  //disables standby setting on both speed controllers
  setGpioPinHigh(STBY);
  setGpioPinHigh(STBY2);
}
void Drivetrain :: stop(){
  //Update speed of all motors to Zero (Full Stop)
  FR.updateSpeed(0);
  FL.updateSpeed(0);
  BR.updateSpeed(0);
  BL.updateSpeed(0);
}
void Drivetrain :: turnLeft(){
  //Turn left - Basic logic is to slow the left motors by one
  //and speed the right motor up by one
  FR.updateSpeed(FR.getSpeed() + 1);
  FL.updateSpeed(FL.getSpeed() - 1);
  BR.updateSpeed(BR.getSpeed() + 1);
  BL.updateSpeed(BL.getSpeed() - 1);
}
void Drivetrain :: turnRight(){
  //Turn right - Basic logic is to slow the right motors by one
  //and speed the left motor up by one
  FR.updateSpeed(FR.getSpeed() - 1);
  FL.updateSpeed(FL.getSpeed() + 1);
  BR.updateSpeed(BR.getSpeed() - 1);
  BL.updateSpeed(BL.getSpeed() + 1);
}
void Drivetrain :: updateSpeed(int speed){
  //Update the speed on all wheels while maintaining any turn arcs
  //Speed input should be the amount we want to speed up
  //With min/max of -255 to 255
  //Use negative integer to slow
  FR.updateSpeed(FR.getSpeed() + speed);
  FL.updateSpeed(FL.getSpeed() + speed);
  BR.updateSpeed(BR.getSpeed() + speed);
  BL.updateSpeed(BL.getSpeed() + speed);
}
