#include "wheel.h"
#include "Arduino.h"

using namespace std;

Wheel :: Wheel(){
          }
        void Wheel :: initalize(int input1, int input2, int pwmIN, char const * sideIN){
          PWM=pwmIN;
          IN1=input1;
          IN2=input2;
          if(strcmp(sideIN,"left") == 0){
            //set side to 0
            side=0;
            }
          else if(strcmp(sideIN,"right") == 0){
            //set side to 1;
            side=1;
            }
          //TODO: remove dependency on arduino library for pinMode
          pinMode(PWM, OUTPUT);
          pinMode(IN1, OUTPUT);
          pinMode(IN2, OUTPUT);
        }
        void Wheel :: setDirection(char const * directionIn, int speedIn){
          if(strcmp(directionIn,"forward") == 0){
            //direction forward was specified
            //set direction to 0
            direction=0;
            }
          else if(strcmp(directionIn,"backward") == 0){
            //direction backward was specified
            //set direction to 1;
            direction=1;
            }
          //set speed
          speed=speedIn;
          writeMotors();
          }
        int Wheel :: getSpeed(){
          return speed;
        }    
        void Wheel :: updateSpeed(int speedIn){
          //Change the speed of the motor
          speed=speedIn;
          writeMotors();
        }
        void Wheel :: writeMotors(){
          //update to speed controller
          boolean IN1OUT = LOW;
          boolean IN2OUT = HIGH;

          if(direction == 1){
            IN1OUT = HIGH;
            IN2OUT = LOW;
            }

          //TODO: remove dependency on arduino library for digitalWrite
          digitalWrite(IN1, IN1OUT);
          digitalWrite(IN2, IN2OUT);
          //TODO: remove dependency on arduino library for analogWrite
          analogWrite(PWM,speed);
        }
