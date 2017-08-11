#include <wheel.h>
#include "Arduino.h"
using namespace std;


  int STBY = 30; //standby
  int STBY2 = 31; //standby2

  //Motor A
  int PWMA = 2; //Speed control
  int AIN1 = 22; //Direction
  int AIN2 = 23; //Direction

  //Motor B
  int PWMB = 3; //Speed control
  int BIN1 = 24; //Direction
  int BIN2 = 25; //Direction

  //Motor C
  int PWMC = 4; //Speed control
  int CIN1 = 26; //Direction
  int CIN2 = 27; //Direction-

  //Motor D
  int PWMD = 5; //Speed control
  int DIN1 = 28; //Direction
  int DIN2 = 29; //Direction

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby
  digitalWrite(STBY2, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else if(motor == 2){
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }else if(motor == 3){
    digitalWrite(CIN1, inPin1);
    digitalWrite(CIN2, inPin2);
    analogWrite(PWMC, speed);
  }else{
    digitalWrite(DIN1, inPin1);
    digitalWrite(DIN2, inPin2);
    analogWrite(PWMD, speed);
  }
}

void stop(){
//enable standby
  digitalWrite(STBY, LOW);
  digitalWrite(STBY2, LOW);
}

void setup(){
  //motor A connected between A01 and A02
  //motor B connected between B01 and B02

  int STBY = 30; //standby
  int STBY2 = 31; //standby2

  //Motor A
  int PWMA = 2; //Speed control
  int AIN1 = 22; //Direction
  int AIN2 = 23; //Direction

  //Motor B
  int PWMB = 3; //Speed control
  int BIN1 = 24; //Direction
  int BIN2 = 25; //Direction

  //Motor C
  int PWMC = 4; //Speed control
  int CIN1 = 26; //Direction
  int CIN2 = 27; //Direction-

  //Motor D
  int PWMD = 5; //Speed control
  int DIN1 = 28; //Direction
  int DIN2 = 29; //Direction

  pinMode(STBY, OUTPUT);
  pinMode(STBY2, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(PWMC, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);

  pinMode(PWMD, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);
}

void loop(){
  move(1, 255, 1); //motor 1, full speed, left
  move(2, 255, 1); //motor 2, full speed, left
  move(3, 255, 1); //motor 1, full speed, left
  move(4, 255, 1); //motor 2, full speed, left

  delay(1000); //go for 1 second
  stop(); //stop
  delay(250); //hold for 250ms until move again

  move(1, 255, 0); //motor 1, half speed, right
  move(2, 255, 0); //motor 2, half speed, right
  move(3, 255, 0); //motor 1, half speed, right
  move(4, 255, 0); //motor 2, half speed, right

  delay(1000);
  stop();
  delay(250);
}
