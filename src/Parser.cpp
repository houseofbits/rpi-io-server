#include "Parser.h"
#include "IOException.h"

Request Parser::parse(std::string request)
{
    Request requestStructure;

    std::istringstream iss(request);

    std::string query;

    if (!(iss >> requestStructure.method >> query >> requestStructure.protocol)) {
        throw IOException("Failed to split request string " + iss.str());
    }

    iss.clear();
    iss.str(query);

    if(!std::getline(iss, requestStructure.url, '?'))
    {
        throw IOException("Failed to get line from request string " + iss.str());
    }

    requestStructure.params = parseRequestStringParams(iss);

    return requestStructure;
}

void Parser::debug(Request request) 
{
    std::cout << "protocol: " << request.protocol << '\n';
    std::cout << "method  : " << request.method << '\n';
    std::cout << "url     : " << request.url << '\n';

    for(auto const& param: request.params)
        std::cout << "param   : " << param.first << " = " << param.second << '\n';
}

ParamsMap Parser::parseRequestStringParams(std::istringstream& request)
{
    ParamsMap params;

    std::string keyval, key, val;

    while(std::getline(request, keyval, '&')) {
        std::istringstream iss(keyval);
        if(std::getline(std::getline(iss, key, '='), val)) {
            params[key] = val;
        }
    }
    return params;
}