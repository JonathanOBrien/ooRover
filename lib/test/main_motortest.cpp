#include <wheel.h>
#include "Arduino.h"
using namespace std;

int BR1 = 22;
int BR2 = 23;
int BRPWM = 2;
int STBY = 30;
int STBY2 = 31;
Wheel BR;

void setup(){
  //Pin Definitions for the drivetrain
  //TODO: move this to a config file
  //Create wheel objects for 4 wheels


  }
int main(){


  pinMode(STBY, OUTPUT);
  pinMode(STBY2, OUTPUT);
  digitalWrite(STBY, HIGH);
  digitalWrite(STBY2, HIGH);
  BR.initalize(BR1,BR2,BRPWM,"right");
  //BR.updateSpeed(120);
  }
