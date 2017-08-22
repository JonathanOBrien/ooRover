<<<<<<< HEAD
#include "InitSystem.h"
#include "Pwm.h"
#include "rover.h"
#include "HMC5883L.h"
#include "USART2.h"
#include "SystemClock.h"
#include "console.h"
#include "string.h"

Serial2 serialOut;
Rover :: Rover(){
  //Initialize the rover
  initSystem();
  initSystemClock();
  //initPwmTimer2();
  initPwmTimer4();
  initPwmTimer3();
  //Setup Compass
  compass.initialize();
  //serialOut.start(9600);
  Drivetrain drivetrain;
  serialOut.start(9600);
  //Console console;
  }

void Rover :: serviceMode(){
<<<<<<< current
  //Service Mode
  int stayHere = 1;
  while (stayHere == 1){
    const char * out = "Service Mode:\r";
    serialOut.println(out);
    serialOut.println("1) Run FR\r");
    serialOut.println("2) Run FL\r");
    serialOut.println("3) Run BR\r");
    serialOut.println("4) Run BL\r");
    serialOut.println("5) Test Compass\r");
    serialOut.println("6) Test FWD Distance Sensor\r");
    serialOut.println("Press x to exit\r");
    serialOut.flush();
    while(serialOut.peek() == -1){
          delayMilliseconds(200);
          }
    int input = serialOut.read();

    switch(input){
      //ASCII 1
      case 49:
        //Run Front Right
        drivetrain.testFR(1);
        serialOut.println("Press any key to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFR(0);
        continue;
      //ASCII 2
      case 50:
        //Run Back Left
        drivetrain.testFL(1);
        serialOut.println("Press x to exit\n\r");
        serialOut.flush();
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFL(0);
        continue;
      //ASCII 3
      case 51:
        //Run Back Right
        drivetrain.testFR(1);
        serialOut.println("Press x to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
            }
        drivetrain.testFR(0);
        continue;
        //ASCII 4
      case 52:
        //Run Back Left
        drivetrain.testBL(1);
        serialOut.println("Press x to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testBL(0);
        continue;
      //ASCUII x
      case 120:
          stayHere = 0;
          continue;
      default:
        serialOut.println("Invalid Entry\n\r");

    }
    run();
  }

}

void Rover :: run(){
  //Main Rover Loop Operation
  while(1){
    //Start into Select Mode menu
    serialOut.write("Select Mode:\n\r");
    serialOut.write("1) Manual Mode\n\r");
    serialOut.write("2) AutoPilot\n\r");
    serialOut.write("3) Service Mode\n\r");
    serialOut.flush();
    while(serialOut.peek() == -1){
          delayMilliseconds(2000);
          }
    int input = serialOut.read();

    switch(input){
      //ASCII 1
      case 49:
        manual();
        continue;
        //ASCII 2
      case 50:
        autoPilot();
        continue;
        //ASCUII 3
      case 51:
        serviceMode();
        continue;
      default:
        serialOut.println("Invalid Entry\n\r");
    }
  }
}
void Rover :: autoPilot(){
  serialOut.println("AutoPilot System Engaged\n\r");
  serialOut.println("Press x to disable\n\r");
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
    if(serialOut.peek() != -1){
      /*if(serialOut.read == 120){
        return;
      }*/
      }
    }
  run();
  }
void Rover :: manual(){
    //Manual Rover Mode
    while(serialOut.peek() == -1){
          delayMilliseconds(2000);
          }
<<<<<<< HEAD
    switch(serialOut.read()){
      case 119:
        //W
        speed=speed+1;
        setSpeed(speed);
<<<<<<< HEAD
        serialOut.println("w\r");
=======
        serialOut.println("w");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 115:
      //S
      speed=speed-1;
      setSpeed(speed);
<<<<<<< HEAD
        serialOut.println("s\r");
=======
        serialOut.println("s");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 97:
        //A
        drivetrain.turnLeft();
<<<<<<< HEAD
        serialOut.println("a\r");
=======
        serialOut.println("a");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 100:
        //D
        drivetrain.turnRight();
        serialOut.println("d\r");
=======
        serialOut.println("d");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 101:
        //E
        setSpeed(255);
        drivetrain.stop();
        continue;
      case 99:
        //C
        setSpeed(0);
<<<<<<< HEAD
        serialOut.println("c\r");
=======
        serialOut.println("c");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 120:
        //X
        break;
      default:
<<<<<<< HEAD
        serialOut.println("Invald Entry\r");
=======
        serialOut.println("Invald Entry");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      }
=======
  //  int input = serialOut.read();
>>>>>>> parent of 4d45810... Enabled Manual Mode
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
=======
  //Service Mode
  int stayHere = 1;
  while (stayHere == 1){
    const char * out = "Service Mode:\r";
    serialOut.println(out);
    serialOut.println("1) Run FR\r");
    serialOut.println("2) Run FL\r");
    serialOut.println("3) Run BR\r");
    serialOut.println("4) Run BL\r");
    serialOut.println("5) Test Compass\r");
    serialOut.println("6) Test FWD Distance Sensor\r");
    serialOut.println("Press x to exit\r");
    serialOut.flush();
    while(serialOut.peek() == -1){
          delayMilliseconds(200);
          }
    int input = serialOut.read();

    switch(input){
      //ASCII 1
      case 49:
        //Run Front Right
        drivetrain.testFR(1);
        serialOut.println("Press any key to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFR(0);
        continue;
      //ASCII 2
      case 50:
        //Run Back Left
        drivetrain.testFL(1);
        serialOut.println("Press any key to exit\n\r");
        serialOut.flush();
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFL(0);
        continue;
      //ASCII 3
      case 51:
        //Run Back Right
        drivetrain.testFR(1);
        serialOut.println("Press any key to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
            }
        drivetrain.testFR(0);
        continue;
        //ASCII 4
      case 52:
        //Run Back Left
        drivetrain.testBL(1);
        serialOut.println("Press any key to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testBL(0);
        continue;
        //ASCII 5
      case 53:
        //Test Compass
        serialOut.println("/n");
        serialOut.println(compass.getHeading());
        serialOut.println("/r");
        continue;
      //ASCUII x
      case 120:
          stayHere = 0;
          break;
      default:
        serialOut.println("Invalid Entry\n\r");
    }
  }

}

void Rover :: run(){
  //Main Rover Loop Operation
  while(1){
    //Start into Select Mode menu
    serialOut.write("Select Mode:\n\r");
    serialOut.write("1) Manual Mode\n\r");
    serialOut.write("2) AutoPilot\n\r");
    serialOut.write("3) Service Mode\n\r");
    serialOut.flush();
    while(serialOut.peek() == -1){
          delayMilliseconds(200);
          }
    int input = serialOut.read();

    switch(input){
      //ASCII 1
      case 49:
        manual();
        continue;
        //ASCII 2
      case 109:
          manual();
          continue;
          //ASCII m
      case 50:
        autoPilot();
        continue;
        //ASCUII 3
      case 51:
        serviceMode();
        continue;
      default:
        serialOut.println("Invalid Entry\n\r");
    }
  }
}
void Rover :: autoPilot(){
  serialOut.println("AutoPilot System Engaged\n\r");
  serialOut.println("Press x to disable\n\r");
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
    if(serialOut.peek() != -1){
      if(serialOut.read() == 120){
        return;
      }
      }
    }
  run();
  }
void Rover :: manual(){
    //Manual Rover Mode
    serialOut.println("Manual Control Activated\r");
    serialOut.println("Commands: WSAD\r");
    int speed = 0;
  while(1){
    while(serialOut.peek() == -1){
          delayMilliseconds(20);
          }
    switch(serialOut.read()){
      case 119:
        //W
        speed=speed+1;
        setSpeed(speed);
<<<<<<< HEAD
        serialOut.println("w\r");
=======
        serialOut.println("w");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 115:
      //S
      speed=speed-1;
      setSpeed(speed);
<<<<<<< HEAD
        serialOut.println("s\r");
=======
        serialOut.println("s");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 97:
        //A
        drivetrain.turnLeft();
<<<<<<< HEAD
        serialOut.println("a\r");
=======
        serialOut.println("a");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 100:
        //D
        drivetrain.turnRight();
<<<<<<< HEAD
        serialOut.println("d\r");
=======
        serialOut.println("d");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 101:
        //E
        setSpeed(255);
        drivetrain.stop();
        continue;
      case 99:
        //C
        setSpeed(0);
<<<<<<< HEAD
        serialOut.println("c\r");
=======
        serialOut.println("c");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      case 120:
        //X
        break;
      default:
<<<<<<< HEAD
        serialOut.println("Invald Entry\r");
=======
        serialOut.println("Invald Entry");
>>>>>>> 069e3f164c719a8a145a857f4021b132ce618537
        continue;
      }
    }
  }
void Rover :: setHeading(int headingIn){
  //0-359
  //Sanitize Data
  if (headingIn > 359) return;
  if (headingIn < 0) return;
  //change desired heading to input
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
>>>>>>> before discard
=======
#include "InitSystem.h"
#include "Pwm.h"
#include "rover.h"
#include "HMC5883L.h"
#include "USART2.h"
#include "SystemClock.h"
#include "console.h"
#include "string.h"

Serial2 serialOut;
Rover :: Rover(){
  //Initialize the rover
  initSystem();
  initSystemClock();
  //initPwmTimer2();
  initPwmTimer4();
  initPwmTimer3();
  //Setup Compass
  compass.initialize();
  //serialOut.start(9600);
  Drivetrain drivetrain;
  serialOut.start(9600);
  //Console console;
  }

void Rover :: serviceMode(){
  //Service Mode
  int stayHere = 1;
  while (stayHere == 1){
    const char * out = "Service Mode:\r";
    serialOut.println(out);
    serialOut.println("1) Run FR\r");
    serialOut.println("2) Run FL\r");
    serialOut.println("3) Run BR\r");
    serialOut.println("4) Run BL\r");
    serialOut.println("5) Test Compass\r");
    serialOut.println("6) Test FWD Distance Sensor\r");
    serialOut.println("Press x to exit\r");
    serialOut.flush();
    while(serialOut.peek() == -1){
          delayMilliseconds(200);
          }
    int input = serialOut.read();

    switch(input){
      //ASCII 1
      case 49:
        //Run Front Right
        drivetrain.testFR(1);
        serialOut.println("Press any key to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFR(0);
        continue;
      //ASCII 2
      case 50:
        //Run Back Left
        drivetrain.testFL(1);
        serialOut.println("Press x to exit\n\r");
        serialOut.flush();
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testFL(0);
        continue;
      //ASCII 3
      case 51:
        //Run Back Right
        drivetrain.testFR(1);
        serialOut.println("Press x to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
            }
        drivetrain.testFR(0);
        continue;
        //ASCII 4
      case 52:
        //Run Back Left
        drivetrain.testBL(1);
        serialOut.println("Press x to exit\n\r");
        while(serialOut.peek() == -1){
              delayMilliseconds(200);
              }
        drivetrain.testBL(0);
        continue;
      //ASCUII x
      case 120:
          stayHere = 0;
          continue;
      default:
        serialOut.println("Invalid Entry\n\r");

    }
    run();
  }

}

void Rover :: run(){
  //Main Rover Loop Operation
  while(1){
    //Start into Select Mode menu
    serialOut.write("Select Mode:\n\r");
    serialOut.write("1) Manual Mode\n\r");
    serialOut.write("2) AutoPilot\n\r");
    serialOut.write("3) Service Mode\n\r");
    serialOut.flush();
    while(serialOut.peek() == -1){
          delayMilliseconds(2000);
          }
    int input = serialOut.read();

    switch(input){
      //ASCII 1
      case 49:
        manual();
        continue;
        //ASCII 2
      case 50:
        autoPilot();
        continue;
        //ASCUII 3
      case 51:
        serviceMode();
        continue;
      default:
        serialOut.println("Invalid Entry\n\r");
    }
  }
}
void Rover :: autoPilot(){
  serialOut.println("AutoPilot System Engaged\n\r");
  serialOut.println("Press x to disable\n\r");
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
    if(serialOut.peek() != -1){
      /*if(serialOut.read == 120){
        return;
      }*/
      }
    }
  run();
  }
void Rover :: manual(){
    //Manual Rover Mode
    while(serialOut.peek() == -1){
          delayMilliseconds(2000);
          }
  //  int input = serialOut.read();
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
>>>>>>> parent of 4d45810... Enabled Manual Mode
