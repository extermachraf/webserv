#include "Parser.hpp"

void    Error_mssg(const char *message){
    std::cout << message << std::endl;
    exit(1);
}

std::string read_file(){
    std::string To_parse;
    std::string line;

    std::fstream file("server.conf");
    if(file.fail())
        Error_mssg("fail to read from server config");
    while(std::getline(file, line)){
        To_parse += line;
        if(!file.eof())
            To_parse += '\n';
    }
    file.close();
    return To_parse;
}
////////////////////////////////////////////////////////////////
//////////////////////split/////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////split with string ////////////////////////////////////
std::vector<std::string> split_with_string(const std::string& to_split, const std::string delimiter){
    std::vector<std::string>    retunr_value;
    std::size_t                 start = 0;
    std::size_t                 end = 0;
    while((end = to_split.find(delimiter, start)) != std::string::npos){
        retunr_value.push_back(to_split.substr(start, end - start));
        start = end + delimiter.length();
    }
    retunr_value.push_back(to_split.substr(start));
    return retunr_value;
}
//////////////////////////////////////////////////////////////////
///////////split with caracter///////////////////////////////////
std::vector<std::string> split_with_carac(std::string str, char delemiter){
    size_t start = 0;
    size_t end = 0;
    std::vector<std::string> return_value;

    while(str[start]){
        while(str[start] && str[start] == delemiter)
            start++;
        if(!str[start])
            break;
        end = start;
        while(str[end] && str[end] != delemiter)
            end++;
        return_value.push_back(str.substr(start, end - start));
        start = end ;
    }
    return return_value;
}
//////////////////////////////////////////////////////////////

std::vector<std::string> take_strings_to_parse(){
    std::string To_parse = read_file();
    std::string delemiter = "server_name";
    std::size_t start = 0;
    std::size_t end = 0;

    while((end = To_parse.find(delemiter, start)) != std::string::npos){
        To_parse.replace(end, delemiter.length(), "name");
        start = end + delemiter.length();
    }
    std::vector<std::string> spl = split_with_string(To_parse, "server");
    spl.erase(spl.begin());
    return spl;
}

/*
struct location{
    bool allows_methodes
    bool root;
    bool autoindex;
    bool index;
}
classe location{
    vector maethodes;
    std::string root;
    std::string autoindex;
    std::string index;
}
struct server{
    bool listen;
    bool error_page;
    bool upload_path;
    bool cgi;
    bool server_name;
    bool locations;
}
 classe server {
    struct server;
    int listen;
    std::map error_pages;
    std::string uplod_path;
    std::map cgi;
    std::map loc(path, location);
}*/