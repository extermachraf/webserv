#ifndef SERVER_HPP
#define SERVER_HPP
#include "../Parser.hpp"
#include "Location.hpp"
struct bool_server{
    bool listen;
    bool error_pages;
    bool upload_path;
    bool cgi;
    bool server_name;
    bool locations;
};

class Server
{
public :
    /////////////////////////////////////////////
    bool_server                         yes_or_no;
    int                                 listen;
    std::string                         server_name;
    std::map<int, std::string>          error_pages;
    std::string                         upload_path;
    std::map<std::string, std::string>          cgi;
    std::map<std::string, Location>  loction;
    //NB!! add locations
    /////////////////////////////////////////////
    Server();
    ~Server();
};

#endif