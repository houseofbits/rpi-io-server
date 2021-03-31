#pragma once

#include <string>

class BasicResponse 
{
    public: 
        std::string httpProtocolVersion;
        std::string httpContentType;
        int statusCode;
        std::string content;

        BasicResponse();

        BasicResponse(int statusCode, std::string content);

        std::string get();

    private:
        std::string response;
        void build();
        void replaceStr(std::string& str, const std::string& from, const std::string& to);
};
