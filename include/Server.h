#include "IOHandler.h"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

class Server {
    public: 

        const static std::string httpSuccessResponse;

        IOHandler ioHandler;

        Parser parser;

        int serverFd;
        
        sockaddr_in address;

        void init(int port);

        void run();


};