#include "Server.h"
#include "IOException.h"
#include "BasicResponse.h"
#include "HttpStatusCodes.h"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

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
    
    long valread;

    Request requestStructure;

    while(1)
    {   
        try{

            //printf("\n--------------- Wait ------------------\n\n");
            
            if ((currentSocket = accept(serverFd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
                continue;
            }
            
            char buffer[30000] = {0};
            valread = read( currentSocket , buffer, 30000);

            std::string request(buffer, 30000);

            requestStructure = parser.parse(request);

            //parser.debug(requestStructure);

            ioHandler.handleRequest(requestStructure);

            createResponse(HttpStatusCode::OK, "OK");
        } catch(IOException &e) {
            std::cout << e.message << std::endl;
            createResponse(HttpStatusCode::BadRequest, e.message);
        }

        close(currentSocket);  
    }   
}

void Server::createResponse(int statusCode, std::string content)
{   
    BasicResponse response;
    response.statusCode = statusCode;
    response.content = content;
    std::string raw = response.get();
    write(currentSocket , raw.c_str(), raw.length()); 
}
