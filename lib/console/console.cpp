#include "USART2.h"
#include "USART3.h"
#include "console.h"

using namespace std;

Serial2 commLink;
Serial3 CVLink;

Console :: Console(){
  //Do Things
  commLink.start(9600);
  CVLink.start(9600);
}
int  checkCommLinkQueue(){
  if(commLink.peek() == -1){
    return 0;
    }
  return 1;
  }
char readCommLinkQueue(){
  return 0;
  }
int  checkCVLinkQueue(){
  if(CVLink.peek() == -1){
    return 0;
    }
  return 1;
  }
char readCVLinkQueue(){
  return 0;
  }
void sendCVLinkComm(char * msg){
  CVLink.write(msg);
  CVLink.write("\r\n");
  return;
  }
void sendCommLinkComm(char * msg){
  commLink.write(msg);
  commLink.write("\r\n");
  return;
  }
void sendDebugMSG(char * msg){
  commLink.write("DEBUG:");
  commLink.write(msg);
  commLink.write("\r\n");
  return;
  }
void sendLogMSG(char * msg){
  commLink.write("LOG:");
  commLink.write(msg);
  commLink.write("\r\n");
  return;
  }

/*
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
