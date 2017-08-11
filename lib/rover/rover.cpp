
#include "rover.h"
#include "HMC5883L.h"

using namespace std;

Rover :: Rover(){
  //Initialize the rover

  //Setup Compass
  compass.initialize();
  }
void Rover :: run(){
  //Main loop of the rover
  //Set heading to current heading at start
  setHeading(compass.getHeading());
  setSpeed(0);
  //Wait 5 seconds
  delay(5000);
  //Go Forward for 5 seconds
  setSpeed(128);
  delay(5000);
  //Go Backwards for 5 seconds
  setSpeed(255);
  delay(5000);

  }
void Rover :: setHeading(int headingIn){
  //0-359
  //Sanitize Data
  if (headingIn > 359) return;
  if (headingIn < 0) return;
  desiredHeading = headingIn;
  }
void Rover :: setSpeed(int speedIn){
  //0-255 to match PWM
  //no negatives
  //TODO: Change input into a more meaningful unit
  //TODO: Santize Data
  desiredSpeed = speedIn;
  }
void Rover :: alterCourse(){
  //turn left or right to meet heading
  //CurrentHeading-DesiredHeading=delta
  int delta = compass.getHeading()-desiredHeading;
  if (delta < 0){
    //if delta negative turn right
    drivetrain.turnRight();
  }
  else if (delta > 0){
    //if delta is positive turn left
    drivetrain.turnLeft();
  }
  //else do nothing, delta = 0,
  }
