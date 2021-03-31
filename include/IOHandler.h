#pragma once

#include <stdint.h>
#include "../abelibs/IOPi/ABE_IoPi.h"
#include "Parser.h"


class IOHandler
{
    public:
        IOHandler();
    
        ABElectronics_CPP_Libraries::IoPi* io1;
        ABElectronics_CPP_Libraries::IoPi* io2;        

        void initIO();

        void handleRequest(Request request);

        void setPortPin(int port, int pin, int state);

};