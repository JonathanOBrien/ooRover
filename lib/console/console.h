#ifndef CONSOLE_H
#define CONSOLE_H
using namespace std;

class Console
{
    public:
        Console();
        int checkMessages();
        char * readMessage();
        void send(char *);
        void sendLine(char *);

};
#endif
