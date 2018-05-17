#include "wheel.h"
#include "ArduinoPins.h"
#include "ioPins.h"
#include "ArduinoPins.h"
#include "InitSystem.h"
#include "SystemClock.h"
#include "Pwm.h"
#include <string.h>
#include <stdint.h>
using namespace std;

Wheel :: Wheel(){
}
        void  Wheel :: initalize(char const * location, char const * sideIN){
          motorLocation = location;
          //Set initial speed to 0
          speed=0;
          signedSpeed=0;
          //Set the initial direction based on the side of the motor
          //Initialize our ouput pins
          //set Pin Modes
          if(strcmp(motorLocation,"FR") == 0){
            setGpioPinModeOutput(FRPWM);
            setGpioPinModeOutput(FR1);
            setGpioPinModeOutput(FR2);
            side=1;
            direction=1;
            }
          else if(strcmp(motorLocation,"FL") == 0){
            setGpioPinModeOutput(FLPWM);
            setGpioPinModeOutput(FL1);
            setGpioPinModeOutput(FL2);
            side=0;
            direction=0;
            }
          else if(strcmp(motorLocation,"BR") == 0){
            setGpioPinModeOutput(BRPWM);
            setGpioPinModeOutput(BR1);
            setGpioPinModeOutput(BR2);
            side=1;
            direction=1;
            }
          else if(strcmp(motorLocation,"BL") == 0){
            setGpioPinModeOutput(BLPWM);
            setGpioPinModeOutput(BL1);
            setGpioPinModeOutput(BL2);
            side=0;
            direction=0;
            }
        }
        void  Wheel :: setDirection(int speedIn){
          //Sets the direction forward or reverse based on the speed inpuit
          if(side == 0){
            //Left Side Motor
            if(speedIn < 0){
              //Reverse
              direction=1;
              }
            else if(speedIn > 0){
              //Forward
              direction=0;
              }
            }
          else if(side == 1){
            //Right side motor
            if(speedIn < 0){
              //Reverse
              direction=0;
              }
            else if(speedIn > 0){
              //Forward
              direction=1;
              }
            }
          }
        int   Wheel :: getSpeed(){
          return signedSpeed;
        }
        int   Wheel :: normalizeSpeed(int speedIn){
          //Limit speed to 255 through -255
          if(speedIn < -255){
            speedIn=-255;
            }
          else if (speedIn > 255){
            speedIn=255;
            }
          signedSpeed=speedIn;
          //Normalize the output to 0-255
          if(speedIn<0){
            //swap the output to positive
            speedIn = speedIn * -1;
            }
          return speedIn;
          }
        void  Wheel :: testMode(int mode){
          //Test this wheel
          if (mode == 1){
            updateSpeed(255);
            }
          else if (mode == 2){
            updateSpeed(-255);
            }
          else{
            updateSpeed(0);
            }
        }
        void  Wheel :: updateSpeed(int speedIn){
          //Set the Direction
          setDirection(speedIn);
          //Normalize the speed
          speed=normalizeSpeed(speedIn);
          //Update the motors
          writeMotor();
        }
        void  Wheel :: writeMotor(){
          //update to speed controller
          if(strcmp(motorLocation,"FR") == 0){
            if(direction == 1){
              //Moving Forward
              setGpioPinLow(FR1);
              setGpioPinHigh(FR2);
              }
            else{
              //Moving Backwards
              setGpioPinHigh(FR1);
              setGpioPinLow(FR2);
              }
            //Update Speed PWM
            writeGpioPinPwm(FRPWM, speed);
            }
          else if(strcmp(motorLocation,"FL") == 0){
            if(direction == 0){
              //Moving Forward
              setGpioPinLow(FL1);
              setGpioPinHigh(FL2);
              }
            else{
              //Moving Backwards
              setGpioPinHigh(FL1);
              setGpioPinLow(FL2);
              }
            //Update Speed PWM
            writeGpioPinPwm(FLPWM, speed);
            }
          else if(strcmp(motorLocation,"BR") == 0){
            if(direction == 1){
              //Moving Forward
              setGpioPinLow(BR1);
              setGpioPinHigh(BR2);
              }
            else{
              //Moving Backwards
              setGpioPinHigh(BR1);
              setGpioPinLow(BR2);
              }
            //Update Speed PWM
            writeGpioPinPwm(BRPWM, speed);
            }
          else if(strcmp(motorLocation,"BL") == 0){
            if(direction == 0){
              //Moving Forward
              setGpioPinLow(BL1);
              setGpioPinHigh(BL2);
              }
            else{
              //Moving Backwards
              setGpioPinHigh(BL1);
              setGpioPinLow(BL2);
              }
            //Update Speed PWM
            writeGpioPinPwm(BLPWM, speed);
            }
        }
