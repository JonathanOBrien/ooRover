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
    if(USART2::peek() == -1){
      return 0;
      }
    return 1;
  }
  char * readMessage(){
    return 0;
  }
  void send(const char content){
    USART2::write(content);
  }
  void sendLine(const char * content){
    USART2::write(content);
    send("\r\n");
  }
