#include "Parser.hpp"

int main(){
    std::vector<std::string> st = take_strings_to_parse();
    std::vector<Server> servers;
    for (size_t i = 0; i < st.size() ; i++){
        std::cout<<i<<std::endl;
        Holder holder(st[i]);
        servers.push_back(parse_data(holder));
    }
    // Holder holder(st[2]);
    // Server server =  parse_data(holder);
    // std::cout<< "port = " <<server.listen<<std::endl;
    // std::cout<< "name = " << server.yes_or_no.server_name <<std::endl;
}