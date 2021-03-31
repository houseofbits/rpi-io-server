#include "Request.h"
#include "IOException.h"

bool Request::isUnsignedInteger(std::string value)
{
    std::size_t found = value.find_first_not_of("0123456789");
    if (found!=std::string::npos) {
        return false;
    }
    return true;
}

bool Request::doParamExist(std::string key)
{
    return !(params.find(key) == params.end());
}

int Request::getIntParam(std::string key)
{
    if (!doParamExist(key)) {
        throw IOException("Param '" + key + "' does not exist");
    }
    if (!isUnsignedInteger(params[key])) {
        throw IOException("Param '" + key + "' is not integer value");
    }
    return std::stoi(params[key]);
}