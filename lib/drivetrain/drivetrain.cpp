#include "wheel.h"
#include "drivetrain.h"
#include "Arduino.h"
using namespace std;

Drivetrain :: Drivetrain(){
  //create wheels for the drivetrain
  //TODO: this needs to support more vehicle types
  //TODO: modular based on number of wheels
  Wheel FR;
  Wheel FL;
  Wheel BR;
  Wheel BL;
  FR.initalize(FR1,FR2,FRPWM,"right");
  FL.initalize(FL1,FL2,FLPWM,"left");
  BR.initalize(BR1,BR2,BRPWM,"right");
  BL.initalize(BL1,BL2,BLPWM,"left");

  //prepare motors for use
  disableStandby();
  }
void Drivetrain :: disableStandby(){
  //disables standby setting on both speed controllers
  //TODO: remove dependency on arduino library for digitalWrite
  digitalWrite(STBY, HIGH);
  digitalWrite(STBY2, HIGH);
}
