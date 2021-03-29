#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <exception>

typedef std::map<std::string, std::string> ParamsMap;

typedef struct {
    std::string method;
    std::string url;
    std::string protocol;        
    ParamsMap params;
} Request;

class Parser {
    public: 
        Request parse(std::string request);
        void debug(Request);
    private:
        ParamsMap parseRequestStringParams(std::istringstream& request);
};