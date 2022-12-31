#include "Parser.hpp"

int main(){
    std::vector<std::string> st = take_strings_to_parse();
    // for(size_t i = 0; i < st.size() ; i++){
    //     std::cout << "************************************\n";
    //     std::cout<<st[i]<<std::endl;
    //     std::cout << "************************************\n";
    // }
    Holder holder(st[0]);
    Server server =  parse_data(holder);
    std::cout<< "port = " <<server.listen<<std::endl;
    std::cout<< "name = " << server.yes_or_no.server_name <<std::endl;
}