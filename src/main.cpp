#include "Server.h"

int main(int argc, char const *argv[])
{
    
    Server server;

    server.init(8888);

    server.run();

    return 1;
}