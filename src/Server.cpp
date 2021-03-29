#include "Server.h"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

const std::string Server::httpSuccessResponse = std::string("HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nOK");

void Server::init(int port)
{
    if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        throw 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( port );

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(serverFd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        throw 2;
    }
    if (listen(serverFd, 10) < 0)
    {
        throw 3;
    }
}

void Server::run()
{
    int addrlen = sizeof(address);
    
    int new_socket;

    long valread;

    Request requestStructure;

    while(1)
    {   
        try{

            printf("\n--------------- Wait ------------------\n\n");
            if ((new_socket = accept(serverFd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
                continue;
            }
            
            char buffer[30000] = {0};
            valread = read( new_socket , buffer, 30000);

            std::string request(buffer, 30000);

            requestStructure = parser.parse(request);

            parser.debug(requestStructure);

            ioHandler.handleRequest(requestStructure);

            write(new_socket , httpSuccessResponse.c_str(), httpSuccessResponse.length());

        } catch(int e) {

        }

        close(new_socket);  
    }
    
}