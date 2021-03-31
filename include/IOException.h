#pragma once

#include <exception>
#include <string>

class IOException : public std::exception
{
  public: 

    std::string message;

    IOException(std::string msg) {
        message = msg;
    }

    virtual const char* what() const throw()
    {
        return message.c_str();
    }

};
