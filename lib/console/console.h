#ifndef CONSOLE_H
#define CONSOLE_H

class Console
{
    public:
        Console();
        int checkMessages();
        char readMessage();
        void send(char *);
        void sendLine(char *);
        void newLine();

};
#endif
