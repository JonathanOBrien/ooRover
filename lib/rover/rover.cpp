#include "InitSystem.h"
#include "Pwm.h"
#include "rover.h"
#include "HMC5883L.h"
#include "USART2.h"
#include "SystemClock.h"

using namespace std;

Rover :: Rover(){
  //Initialize the rover
  initSystem();
  initSystemClock();
  initPwmTimer2();
  initPwmTimer4();
  initPwmTimer3();
  initSystemClock();
  //Setup Compass
  compass.initialize();
  USART2::start(9600);
  Drivetrain drivetrain;
  }
void Rover :: run(){
  //Main Rover Loop Operation
  while(1){
    //Start in "Service Mode"
    USART2::write("Service Mode: \r\n 1) Manual \r\n 2) Auto \r\n");
    USART2::flush();

    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
    int input = USART2::read();
    USART2::write(input);
    USART2::write("\r\n");

    switch(input){
      //ASCII 1
      case 49:
        manual();
        return;
        //ASCII 2
      case 50:
        autoPilot();
        return;
      default:
        USART2::write("Invalid Entry");
        USART2::write("\r\n");
      }
    }

  }
void Rover :: autoPilot(){
  USART2::write("AutoPilot System Engaged");
  USART2::write("\r\n");
  USART2::write("Press x to disable");
  USART2::write("\r\n");
  //Main loop of the rover
  //Set heading to current heading at start
  while(1){
    setHeading(compass.getHeading());
    USART2::write(compass.getHeading());
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
    //Main loop of the rover
    //Set heading to current heading at start
    setHeading(compass.getHeading());
    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
    int input = USART2::read();
    USART2::write(input);
    USART2::write("\r\n");
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
