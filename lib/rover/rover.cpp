#include "InitSystem.h"
#include "Pwm.h"
#include "rover.h"
#include "HMC5883L.h"
#include "USART2.h"
#include "SystemClock.h"
#include "console.h"
#include "string.h"

using namespace std;
Console console;
Rover :: Rover(){
  //Initialize the rover
  initSystem();
  initSystemClock();
  initPwmTimer2();
  initPwmTimer4();
  initPwmTimer3();
  //Setup Compass
  compass.initialize();
  //USART2::start(9600);
  Drivetrain drivetrain;
  }
void Rover :: run(){
  //Main Rover Loop Operation
  while(1){
    //Start into Select Mode menu
    console.sendLine("Select Mode:");
    console.sendLine("1) Manual");
    console.sendLine("2) AutoPilot");
    console.sendLine("2) AutoPilot");

    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
    int input = USART2::read();

    switch(input){
      //ASCII 1
      case (int)1:
        manual();
        return;
        //ASCII 2
      case (int)2:
        autoPilot();
        return;
        //ASCUII 3
      case (int)3:
        serviceMode();
        return;
      default:
        console.send("Invalid Entry");
      }
    }

  }
void Rover :: autoPilot(){
  console.sendLine("AutoPilot System Engaged");
  console.sendLine("Press x to disable");
  //Main loop of the rover
  //Set heading to current heading at start
  while(1){
    setHeading(compass.getHeading());
    //console.send(compass.getHeading());
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


  }
void Rover :: manual(){
    //Manual Rover Mode
    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
    int input = USART2::read();
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
  drivetrain.updateSpeed(desiredSpeed);
  }
void Rover :: alterCourse(){
  //turn left or right to meet heading
  //CurrentHeading-DesiredHeading=delta
  int delta = (int)compass.getHeading()-desiredHeading;
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
void serviceMode(){
  console.sendLine("Service Mode:");
  console.sendLine("1) Run FR");
  console.sendLine("2) Run FL");
  console.sendLine("3) Run BR");
  console.sendLine("4) Run BL");
  console.sendLine("5) Test Compass");
  console.sendLine("6) Test FWD Distance Sensor");
  }
