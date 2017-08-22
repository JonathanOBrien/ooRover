#include "USART2.h"
#include "console.h"

using namespace std;

Serial2 serialOut;

Console :: Console(){
  //Do Things
  //serialOut.start(9600);
}/*
  int checkMessages(){
    if(serialOut.peek() == -1){
      return 0;
      }
    return 1;
  }
  char * readMessage(){
    return 0;
  }
  void send(char * content){
    serialOut.write(content);
    return;
  }
  void sendLine(char * content){
    serialOut.write(content);
    serialOut.write("\r\n");
    return;
  }
  void newLine(){
    serialOut.write("\r\n");
    return;
  }
*/
