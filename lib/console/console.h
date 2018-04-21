#ifndef CONSOLE_H
#define CONSOLE_H

class Console
{
    public:
        Console();
        int  checkCommLinkQueue();
        char readCommLinkQueue();
        char readCVLinkQueue();
        int  checkCVLinkQueue();
        void sendCVLinkComm(char * msg);
        void sendCommLinkComm(char * msg);
        void sendDebugMSG(char * msg);
        void sendLogMSG(char * msg);
};
#endif
