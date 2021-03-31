#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <exception>

typedef std::map<std::string, std::string> ParamsMap;

class Request {
    public:
        std::string method;
        std::string url;
        std::string protocol;        
        ParamsMap params;

        int getIntParam(std::string);

        bool doParamExist(std::string);

    private:
        bool isUnsignedInteger(std::string);        
};
