
#include <wheel.h>
#include <stdint.h>
#include "wheel.h"
#include "Pwm.h"
#include "ArduinoPins.h"
#include "InitSystem.h"
#include "SystemClock.h"
#include <string.h>
#include <ioPins.h>
using namespace std;

//Create wheel objects for 4 wheels
Wheel FR = Wheel();
Wheel FL = Wheel();
Wheel BR = Wheel();
Wheel BL = Wheel();

int main(){
  initSystem();
  initPwmTimer4();
  initPwmTimer3();

  setGpioPinModeOutput(STBY);
  setGpioPinModeOutput(STBY2);
  setGpioPinHigh(STBY);
  setGpioPinHigh(STBY2);

  //Initalize wheel objects for 4 wheels
  FR.initalize("FR","right");
  FL.initalize("FL","left");
  BR.initalize("BR","right");
  BL.initalize("BL","left");
  while (1){
    BR.updateSpeed(120);
    FL.updateSpeed(120);
    FR.updateSpeed(120);
    BL.updateSpeed(120);
  }

  }
