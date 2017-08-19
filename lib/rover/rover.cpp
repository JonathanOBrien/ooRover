#include "InitSystem.h"
#include "Pwm.h"
#include "rover.h"
#include "HMC5883L.h"
#include "USART2.h"
#include "SystemClock.h"
#include "console.h"
#include "string.h"

using namespace std;



Rover :: Rover(){
  //Initialize the rover
  initSystem();
  initSystemClock();
  initPwmTimer2();
  initPwmTimer4();
  initPwmTimer3();
  //Setup Compass
  compass.initialize();
  USART2::start(9600);
  Drivetrain drivetrain;
  Console console;
  }

void Rover :: serviceMode(){
  //Service Mode
  int stayHere = 1;
  while (stayHere == 1){
    USART2::write("Service Mode:");
    USART2::flush();
    USART2::write("\r\n");
    USART2::write("1) Run FR");
    USART2::write("\r\n");
    USART2::write("2) Run FL");
    USART2::write("\r\n");
    USART2::write("3) Run BR");
    USART2::write("\r\n");
    USART2::write("4) Run BL");
    USART2::write("\r\n");
    USART2::write("5) Test Compass");
    USART2::write("\r\n");
    USART2::write("6) Test FWD Distance Sensor");
    USART2::write("\r\n");
    USART2::write("Press x to exit");
    USART2::write("\r\n");
    USART2::flush();
    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
    int input = USART2::read();

    switch(input){
      //ASCII 1
      case 49:
        //Run Front Right
        drivetrain.testFR(1);
        USART2::write("Press x to exit");
        USART2::write("\r\n");
        while(USART2::peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFR(0);
        return;
      //ASCII 2
      case 50:
        //Run Back Left
        drivetrain.testFL(1);
        USART2::write("Press x to exit");
        USART2::write("\r\n");
        USART2::flush();
        while(USART2::peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFL(0);
        return;
      //ASCII 3
      case 51:
        //Run Back Right
        drivetrain.testFR(1);
        USART2::write("Press x to exit");
        USART2::write("\r\n");
        while(USART2::peek() == -1){
              delayMilliseconds(200);
            }
        drivetrain.testFR(0);
        return;
        //ASCII 4
      case 52:
        //Run Back Left
        drivetrain.testBL(1);
        USART2::write("Press x to exit");
        USART2::write("\r\n");
        while(USART2::peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testBL(0);
        return;
      //ASCUII x
      case 53:
        stayHere = 0;
        return;
      default:
        USART2::write("Invalid Entry");

    }
  }
}

void Rover :: run(){
  //Main Rover Loop Operation
  while(1){
    //Start into Select Mode menu
    USART2::write("Select Mode:");
    USART2::write("\r\n");
    USART2::write("1) Manual Mode");
    USART2::write("\r\n");
    USART2::write("2) AutoPilot");
    USART2::write("\r\n");
    USART2::write("3) Service Mode");
    USART2::write("\r\n");
    USART2::flush();
    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
    int input = USART2::read();

    switch(input){
      //ASCII 1
      case 49:
        manual();
        return;
        //ASCII 2
      case 50:
        autoPilot();
        return;
        //ASCUII 3
      case 51:
        serviceMode();
        return;
      default:
        USART2::write("Invalid Entry");
    }
  }
}
void Rover :: autoPilot(){
  USART2::write("AutoPilot System Engaged\r\n");
  USART2::write("Press x to disable");
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
    if(USART2::peek() != -1){
      if(USART2::read == 120){
        return;
        }
      }
    }
  }
void Rover :: manual(){
    //Manual Rover Mode
    while(USART2::peek() == -1){
          delayMilliseconds(2000);
          }
  //  int input = USART2::read();
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
