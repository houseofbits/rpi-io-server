#include "IOHandler.h"
#include <stdexcept>
#include "IOException.h"

IOHandler::IOHandler() : io1(), io2()
{   
    initIO();
}

void IOHandler::initIO() 
{
    try{

        io1 = new ABElectronics_CPP_Libraries::IoPi(0x20);
        io1->set_port_direction(0, 0x00);
        io1->set_port_direction(1, 0x00);        
        io1->write_port(0, 0xFF);
        io1->write_port(1, 0xFF);

        io2 = new ABElectronics_CPP_Libraries::IoPi(0x21);

        io2->set_port_direction(0, 0x00);
        io2->set_port_direction(1, 0x00);
        io2->write_port(0, 0xFF);
        io2->write_port(1, 0xFF);
	}
	catch (std::exception &e)
	{
		std::cout <<"Initialisation error: "<< e.what() << std::endl;
	}
}

void IOHandler::handleRequest(Request request)
{
    if (request.url == "/set-port-pins") {
        int port = request.getIntParam("port");

        for (int pinNumber = 0; pinNumber < 16; pinNumber++) {
            std::string pinName = "pin" + std::to_string(pinNumber);
            if (request.doParamExist(pinName)) {
                int state = request.getIntParam(pinName);
                setPortPin(port, pinNumber, state);
            }
        }
    }
}

void IOHandler::setPortPin(int port, int pin, int state)
{   
    if (port != 0 && port != 1) {
        throw IOException("Wrong port number");
    }
    if (port == 0 && !io1) {
        throw IOException("Port 1 is not initialized");
    }
    if (port == 1 && !io2) {
        throw IOException("Port 2 is not initialized");
    }    
    if (state != 0 && state != 1) {
        throw IOException("Wrong state");
    }   

    //Invert state
    state = (state == 0) ? 1 : 0;
    
    if (port == 0 && io1) {
        io1->write_pin(pin, state);
    }
    if (port == 1 && io2) {
        io2->write_pin(pin, state);
    }   
}