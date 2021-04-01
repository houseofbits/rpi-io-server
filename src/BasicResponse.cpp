#include "BasicResponse.h"
#include "HttpStatusCodes.h"

BasicResponse::BasicResponse() : 
    httpContentType("text/plain"), 
    httpProtocolVersion("HTTP/1.1")
{   }

BasicResponse::BasicResponse(int statusCode, std::string content) : 
    httpContentType("text/plain"), 
    httpProtocolVersion("HTTP/1.1"),
    statusCode(statusCode),
    content(content)
{   }

void BasicResponse::build()
{
    response = httpProtocolVersion;
    response += " ";
    response += std::to_string(statusCode);
    response += " ";
    response += httpStatusReasonPhrase(statusCode);
    response += "\n";
    response += "Content-Type: ";
    response += httpContentType;
    response += "\n";
    response += "Access-Control-Allow-Origin: *\n";
    response += "Content-Length: ";
    response += std::to_string(content.size());
    response += "\n\n";
    response += content;    
}

std::string BasicResponse::get()
{
    build();
    return response;
}

void BasicResponse::replaceStr(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos) {
        return;
    }
    str.replace(start_pos, from.length(), to);
}


