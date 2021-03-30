#include <stdint.h>
#include "../lib/abelibs/IOPi/ABE_IoPi.h"
#include "Parser.h"

class IOHandler
{
    public:
        IOHandler();
    
        ABElectronics_CPP_Libraries::IoPi io1;
        ABElectronics_CPP_Libraries::IoPi io2;        

        void handleRequest(Request request);

};