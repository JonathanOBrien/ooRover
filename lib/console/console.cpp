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
  void send(char * content){
    USART2::write(content);
    return;
  }
  void sendLine(char * content){
    USART2::write(content);
    USART2::write("\r\n");
    return;
  }
  void newLine(){
    USART2::write("\r\n");
    return;
  }
