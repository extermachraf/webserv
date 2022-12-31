
#include "../Parser.hpp"
Server::Server(){
    yes_or_no.listen = false;
    yes_or_no.error_pages = false;
    yes_or_no.upload_path = false;
    yes_or_no.cgi = false;
    yes_or_no.server_name = false;
    yes_or_no.locations = false;
}

Server::~Server(){

}

Location::Location(){
    yes_no.methodes = false;
    yes_no.root = false;
    yes_no.autoindex = false;
    yes_no.index = false;
    yes_no.path = false;
}

Location::~Location(){

}