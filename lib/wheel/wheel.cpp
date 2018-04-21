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
          //Set the default direction based on the side of the motor
          if(strcmp(sideIN,"left") == 0){
            //set side to 0
            direction=0;
            }
          else if(strcmp(sideIN,"right") == 0){
            //set side to 1;
            direction=1;
            }
          //Initialize our ouput pins
          //set Pin Modes
          if(strcmp(motorLocation,"FR") == 0){
            setGpioPinModeOutput(FRPWM);
            setGpioPinModeOutput(FR1);
            setGpioPinModeOutput(FR2);
            }
          else if(strcmp(motorLocation,"FL") == 0){
            setGpioPinModeOutput(FLPWM);
            setGpioPinModeOutput(FL1);
            setGpioPinModeOutput(FL2);
            }
          else if(strcmp(motorLocation,"BR") == 0){
            setGpioPinModeOutput(BRPWM);
            setGpioPinModeOutput(BR1);
            setGpioPinModeOutput(BR2);
            }
          else if(strcmp(motorLocation,"BL") == 0){
            setGpioPinModeOutput(BLPWM);
            setGpioPinModeOutput(BL1);
            setGpioPinModeOutput(BL2);
            }
        }
        void  Wheel :: setDirection(int directionIn){
          //Sets the direction forward or reverse
          //1 = forward
          //0 = reverse
          //2 = swap to opposite of current
          if(directionIn == 1){
            //direction forward was specified
            //set direction to 1
            direction=1;
            }
          else if(directionIn == 0){
            //direction backward was specified
            //set direction to 0;
            direction=0;
            }
          else if(directionIn == 2){
            //reverse Direction
            //set direction to ?;
            if(direction == 0){
              direction=1;
              }
            else{
              direction=0;
              }
            }
          writeMotors();
          }
        int   Wheel :: getSpeed(){
          return speed;
        }
        void  Wheel :: testMode(int mode){
          //Test this wheel
          if (mode == 1){
            updateSpeed(255);
            }
          else{
            updateSpeed(0);
            }
        }
        void  Wheel :: updateSpeed(int speedIn){
/*        //Check if we need to change the direction
          //(lnzs < 0 && speedIn < 0) || (lnzs > 0 && speedIn > 0)
          if((lastNonZeroSpeed < 0 && speedIn > 0) || (lastNonZeroSpeed > 0 && speedIn < 0)){
            //Set direction to 2 (swap current direction)
            setDirection(2);
            }
          //Set the last non-zero speed
          if (speed != 0){
            lastNonZeroSpeed = speed;
          }*/
          //Update current speed
          speed=speedIn;
          if(speed < -255){
            //Don't let the speed go below 0
            speed = -255;
            }
          else if(speed > 255){
            //Don't let the speed go above 255
            speed=255;
          }
          //Updte the motors
          writeMotors();
        }
        void  Wheel :: writeMotors(){
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
