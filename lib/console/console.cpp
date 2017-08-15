#include "ArduinoMegaPins.h"
#include "InitSystem.h"
#include "SystemClock.h"
#include "USART2.h"
#include "console.h"

using namespace std;

Console :: Console(){
  //Do Things
    USART2::start(9600);
  }
  int checkMessages(){
    return 0;
  }
  char * readMessage(){
    return 0;
  }
  void send(char * content){
    USART2::write(content);
  }
  void sendLine(char * content){
    send(content);
    send("\r\n");
  }
