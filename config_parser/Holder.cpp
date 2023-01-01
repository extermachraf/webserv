#include "Parser.hpp"
void    Holder::check_brackets(){
    int bracket = 0;
    for(int i = 0; server[i];i++)
        if(server[i] == '{' || server[i] == '}')
            bracket++;
    if(bracket % 2 != 0)
    {
        std::cout<< "close your brackets" << std::endl;
        exit(1);
    }
}

Holder::Holder(std::string serv){
    server = serv;
    check_brackets();
    index = 0;
    second_index = 0;
    am_here = serv[0];
    var_to_check = 0;
}


void    Holder::advance(){
    if(server[index + 1])
    {
        index++;
        am_here = server[index];
    }
}

void    Holder::skip_all(){
    while(server[index] <= 32 || server[index] == '\n')
        advance();
}

void    Holder::skip_spaces(){
    while(server[index] <= 32)
        advance();
}

void    Holder::updait(size_t ind){
    if(server[ind]){
        index = ind;
        am_here = server[index];
    }
}

size_t Holder::find_endof_line(){
    second_index = index;
    while(server[second_index] && server[second_index] != '\n')
        second_index++;
    return second_index;
}

std::string Holder::take_id(){
    std::string return_value;
    while(am_here  && (am_here != ' ' && am_here != '\n')){
        return_value += am_here;
        advance();
    }
    return return_value;
}
std::string Holder::take_id_(){
    std::string return_value;
    while(am_here  &&  am_here != '\n'){
        return_value += am_here;
        advance();
    }
    return return_value;
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
        //take_tokens//
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


////////////////take port/////////////////////
bool    check_is_digit(std::string tmp){
    for(int i = 0; tmp[i] ; i++){
        if(!isdigit(tmp[i]))
            return true;
    }
    return false;
}
size_t Holder::take_port(){
    int         return_value;
    skip_spaces();
    std::string tmp = take_id();

    if(check_is_digit(tmp))
    {
        std::cout<<"you can't inser a non digit in you port" << std::endl;
        exit(1);
    }
    for(int i = 0; tmp[i] ; i++){
        if(!isdigit(tmp[i]))
        {
            std::cout<<"you can't inser a non digit in you port" << std::endl;
            exit(1);
        }
    }
    return_value = atoi(tmp.c_str());
    skip_all();
    return return_value;
}

////////////take_error_pages////////////////////
void    print_eror(std::string eroor){
    std::cout<<eroor<<std::endl;
    exit(1);
}
std::map<int, std::string> pick_er_pages(std::vector<std::string> data){
    std::map<int, std::string> er_pages;
    size_t                     counter = 0;

    if((data.size() % 2))
        print_eror("you need to inser a valide error pages");
    for(counter = 0 ; counter < data.size() ; counter++){
        if(check_is_digit(data[counter]))
            print_eror("you need to inser a valide error pages");
        int number = atoi(data[counter].c_str());
        counter++;
        er_pages[number] = data[counter];
    }
    return er_pages;
}

std::map<int, std::string> Holder::take_error_pages(){
    std::map<int, std::string>  er_pages;
    std::string                 storing = take_id_();

    er_pages = pick_er_pages(split_with_carac(storing, ' '));
    skip_all();
    return er_pages;
}
/////////////////////////////////////////////////
////////////////upload_path//////////////////////

std::string Holder::take_upload_path(){
    std::string upload_path;

    skip_spaces();
    upload_path = take_id();
    skip_all();
    return upload_path;
}
/////////////////////////////////////////////////
////////////////cgi//////////////////////////////
void    Holder::take_cgi(){
    skip_spaces();
    std::vector<std::string> data = split_with_carac(take_id_(), ' ');
    if(data.size() != 2 || (data[1] != ".php"
        && data[1] != ".py"))
        print_eror("CGI invalide");
    tmp[data[1]] = data[0];
    skip_all();
}
///////////////////////////////////////////////////
//////take location////////////////////////////////
///////////////////////////////////////////////////
//take location path
std::string Holder::take_loc_path(){
    skip_spaces();
    std::string path = take_id();
    skip_all();
    // std::cout<<am_here<<std::endl;
    // std::cout<<path<<std::endl;

    if(am_here != '{')
        print_eror("location must be followed by {");
    second_index = index;
    while(server[second_index] != '}')
        second_index++;
    if(!server[second_index])
        print_eror("location must be closed with }");
    advance();
    skip_all();
    return path;
}

////pick methodes
std::vector<std::string> Holder::pick_methodes(){
    skip_spaces();
    std::string tmp = take_id_();
    std::vector<std::string> methodes = split_with_carac(tmp, ' ');
    if(methodes.size() > (size_t)4)
        print_eror("you can enter only 3 methodes");
    for(size_t counter = 0; counter < methodes.size(); counter++){
        // std::cout<<methodes[counter]<<std::endl;
        if(methodes[counter] != "POST" && methodes[counter] != "GET" && methodes[counter] != "DELETE")
            print_eror("methodes not allowed");
    }
    skip_all();
    return methodes;
}
/////pick root
std::string Holder::pick_root(){
    skip_spaces();
    std::string root = take_id();
    // std::cout<<root<<std::endl;
    skip_all();
    return root;
}
std::string  Holder::pick_index(){
    skip_spaces();
    std::string index = take_id();
    // std::cout<<root<<std::endl;
    skip_all();
    return index;
}

std::string Holder::take_server_name(){
    skip_spaces();
    std::string server_name = take_id();
    skip_all();
    return server_name;
}

int Holder::pick_autoindex(){
    int     return_value;
    skip_spaces();
    std::string autoindex = take_id();
    if(autoindex == "on")
        return_value = ON;
    else if(autoindex == "off")
        return_value = OFF;
    else
        print_eror("use ON or OFF only to define your autoindex");
    // std::cout<<root<<std::endl;
    skip_all();
    return return_value;
}

Holder::~Holder(){
}