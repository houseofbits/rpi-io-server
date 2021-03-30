#include "IOHandler.h"

IOHandler::IOHandler() : io1(0x20), io2(0x21)
{   
    io1.set_port_direction(0, 0x00);
    io1.set_port_direction(1, 0x00);        
    io1.write_port(0, 0xFF);
    io1.write_port(1, 0xFF);

    io2.set_port_direction(0, 0x00);
    io2.set_port_direction(1, 0x00);        
    io2.write_port(0, 0xFF);
    io2.write_port(1, 0xFF);    
}

void IOHandler::handleRequest(Request request)
{
    if (request.url == "/set-port-pins") {
        std::cout << "Set port pins" << std::endl;

        

        

    }
}