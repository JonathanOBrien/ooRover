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
  updateSpeed(0);
  }
void  Drivetrain :: turnLeft(){
<<<<<<< HEAD
  //Turn left - Basic logic is to slow the left motors by n
  //and speed the right motor up by n
=======
  //Turn left - Basic logic is to slow the left motors by one
  //and speed the right motor up by one
>>>>>>> e25a7887afaaf102b2e5aa2cf7921f616ef224e1
  FR.updateSpeed(FR.getSpeed() + minIncrement);
  FL.updateSpeed(FL.getSpeed() - minIncrement);
  BR.updateSpeed(BR.getSpeed() + minIncrement);
  BL.updateSpeed(BL.getSpeed() - minIncrement);
  }
void  Drivetrain :: turnRight(){
<<<<<<< HEAD
  //Turn right - Basic logic is to slow the right motors by n
  //and speed the left motor up by n
=======
  //Turn right - Basic logic is to slow the right motors by one
  //and speed the left motor up by one
>>>>>>> e25a7887afaaf102b2e5aa2cf7921f616ef224e1
  FR.updateSpeed(FR.getSpeed() - minIncrement);
  FL.updateSpeed(FL.getSpeed() + minIncrement);
  BR.updateSpeed(BR.getSpeed() - minIncrement);
  BL.updateSpeed(BL.getSpeed() + minIncrement);
  }
void  Drivetrain :: accelerate(){
    //Turn right - Basic logic is to slow the right motors by n
    //and speed the left motor up by n
    FR.updateSpeed(FR.getSpeed() + minIncrement);
    FL.updateSpeed(FL.getSpeed() + minIncrement);
    BR.updateSpeed(BR.getSpeed() + minIncrement);
    BL.updateSpeed(BL.getSpeed() + minIncrement);
    }
void  Drivetrain :: decelerate(){
    //Turn right - Basic logic is to slow the right motors by n
    //and speed the left motor up by n
    FR.updateSpeed(FR.getSpeed() - minIncrement);
    FL.updateSpeed(FL.getSpeed() - minIncrement);
    BR.updateSpeed(BR.getSpeed() - minIncrement);
    BL.updateSpeed(BL.getSpeed() - minIncrement);
    }
int   Drivetrain :: calcDelta(int speedIn, int operation) {
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
  if(speed < 0){
    //Don't let the speed go below 0
    speed = 0;
    }
  else if(speed > 255){
    //Don't let the speed go above 255
    speed=255;
  }
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
