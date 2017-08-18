#ifndef CONSOLE_H
#define CONSOLE_H
using namespace std;

class Console
{
    public:
        Console();
        int checkMessages();
        char readMessage();
        void send(const char*);
        void sendLine(const char*);

};
#endif
