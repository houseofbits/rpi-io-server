#pragma once

#include "IOHandler.h"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

class Server {
    public: 

        IOHandler ioHandler;

        Parser parser;

        int serverFd;
        
        sockaddr_in address;

        int currentSocket;

        void init(int port);

        void run();

        void createResponse(int statusCode, std::string content);

};