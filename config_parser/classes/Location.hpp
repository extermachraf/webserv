#ifndef LOCATION_HPP
#define LOCATION_HPP
#include "../Parser.hpp"

struct bool_location{
    bool methodes;
    bool root;
    bool autoindex;
    bool index;
    bool path;
};

class Location
{
public:
    ///////////////////////////////////////////////////
    bool_location               yes_no;
    std::vector<std::string>    methodes;
    std::string                 root;
    int                         autoindex;
    std::string                 index;
    ///////////////////////////////////////////////////
    ///////////////////////////////////////////////////
    Location();
    ~Location();
};

#endif