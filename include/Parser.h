#pragma once

#include "Request.h"
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <exception>

class Parser {
    public: 
        Request parse(std::string request);
        void debug(Request);
    private:
        ParamsMap parseRequestStringParams(std::istringstream& request);
};