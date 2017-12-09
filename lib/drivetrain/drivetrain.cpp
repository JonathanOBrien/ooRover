#include "drivetrain.h"
#include "wheel.h"
#include <ioPins.h>
#include "ArduinoMegaPins.h"
#include "InitSystem.h"
#include "SystemClock.h"
using namespace std;

//Define the minimum increment
int minIncrement = 32;
int nextDirection = 0;

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
void  Drivetrain :: disableStandby(){
  //disables standby setting on both speed controllers
  setGpioPinHigh(STBY);
  setGpioPinHigh(STBY2);
  }
void  Drivetrain :: stop(){
  //Update speed of all motors to Zero (Full Stop)
  FR.updateSpeed(0);
  FL.updateSpeed(0);
  BR.updateSpeed(0);
  BL.updateSpeed(0);
  }
void  Drivetrain :: turnLeft(){
  //Turn left - Basic logic is to slow the left motors by one
  //and speed the right motor up by one
  FR.updateSpeed(calcDelta(FR.getSpeed(), 1));
  FR.setDirection(nextDirection);
  FL.updateSpeed(calcDelta(FL.getSpeed(), 0));
  FL.setDirection(nextDirection);
  BR.updateSpeed(calcDelta(BR.getSpeed(), 1));
  BR.setDirection(nextDirection);
  BL.updateSpeed(calcDelta(BL.getSpeed(), 0));
  BL.setDirection(nextDirection);
  }
void  Drivetrain :: turnRight(){
  //Turn right - Basic logic is to slow the right motors by one
  //and speed the left motor up by one
  FR.updateSpeed(calcDelta(FR.getSpeed(), 0));
  FR.setDirection(nextDirection);
  FL.updateSpeed(calcDelta(FL.getSpeed(), 1));
  FL.setDirection(nextDirection);
  BR.updateSpeed(calcDelta(BR.getSpeed(), 0));
  BR.setDirection(nextDirection);
  BL.updateSpeed(calcDelta(BL.getSpeed(), 1));
  BL.setDirection(nextDirection);
  }

int Drivetrain :: calcDelta(int speedIn, int operation) {
  //Operation 1 = Addition, 0 = Subtraction
  //if current speed -/+ minIncrement < 0
  //Run this for each motor
  float delta;
  //Subtraction
  if (operation == 0){
    delta = speedIn - minIncrement;
    if(delta < 0){
      nextDirection = 1;
    }
    else{
      nextDirection = 0;
    }
  }
    //Addition
  else{
    delta = speedIn + minIncrement;
    if (delta < 0){
      nextDirection = 0;
      }
    else{
      nextDirection = 1;
      }
    }
  return static_cast<int>(delta);

  //set direction 1
  //if current speed -/+ minIncrement > 0
  //Set direction 0
  //updateSpeed to delta
}


void  Drivetrain :: updateSpeed(int speedIn){
  //Does not maintain arcs
  //Speed input should be the new speed
  //With min/max of 0 to 255
  //Use negative integer to reverse
  speed=speedIn;
  FR.updateSpeed(speed);
  FL.updateSpeed(speed);
  BR.updateSpeed(speed);
  BL.updateSpeed(speed);
  }
void  Drivetrain :: testBR(int in){
  if (in == 1){
    BR.updateSpeed(255);
    }
  else{
    BR.updateSpeed(0);
    }
  }
void  Drivetrain :: testBL(int in){
  if (in == 1){
    BL.updateSpeed(255);
    }
  else{
    BL.updateSpeed(0);
    }
  }
void  Drivetrain :: testFL(int in){
  if (in == 1){
    FL.updateSpeed(255);
    }
  else{
    FL.updateSpeed(0);
    }
  }
void  Drivetrain :: testFR(int in){
  if (in == 1){
    FR.updateSpeed(255);
    }
  else{
    FR.updateSpeed(0);
    }
}
int   Drivetrain :: getMI(){
  return minIncrement;
  }
