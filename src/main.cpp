#include "InitSystem.h"
#include "Pwm.h"
#include "drivetrain.h"
using namespace std;

int main(){
  initSystem();
  initPwmTimer2();
  initPwmTimer4();
  initPwmTimer3();
  //Rover rover;
  Drivetrain drivetrain;
  while(1){
    drivetrain.updateSpeed(255);
    //rover.run();

    }
  }
