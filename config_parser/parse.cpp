#include "Parser.hpp"

Location    take_location(Holder &holder){
    Location loc;
    std::string id;

    while(holder.am_here && holder.am_here != '}'){
        id = holder.take_id();
        holder.skip_all();
        if(id == "allow_methods" && loc.yes_no.methodes == false){
            loc.yes_no.methodes = true;
            loc.methodes = holder.pick_methodes();
        }
        else if(id == "root" && loc.yes_no.root == false){
            loc.yes_no.root = true;
            loc.root = holder.pick_root();
        }
        else if(id == "autoindex" && loc.yes_no.autoindex == false){
            loc.yes_no.autoindex = true;
            loc.autoindex = holder.pick_autoindex();
        }
        else if(id == "index" && loc.yes_no.index == false){
            loc.yes_no.index = true;
            loc.index = holder.pick_index();
        }
        else
            print_eror("error in location");
    }
    holder.advance();
    return(loc);
}

Server  parse_data(Holder& holder){
    Server      server;
    std::string id;

    holder.skip_all();
    holder.advance();
    while(holder.am_here && holder.am_here != '}'){
        holder.skip_all();
        id = holder.take_id();
        std::cout<<id<<std::endl;
        if(id == "listen" && server.yes_or_no.listen == false){
            server.yes_or_no.listen = true;
            server.listen = holder.take_port();
        }
        else if(id == "error_page" && server.yes_or_no.error_pages == false){
            server.yes_or_no.error_pages = true;
            server.error_pages = holder.take_error_pages();
        }
        else if(id == "upload_path" && server.yes_or_no.upload_path == false){
            server.yes_or_no.upload_path = true;
            server.upload_path = holder.take_upload_path();
        }
        else if(id == "cgi"){
            server.yes_or_no.cgi = true;
            holder.take_cgi();
        }
        else if(id == "name" && server.yes_or_no.server_name == false){
            server.yes_or_no.server_name = true;
            server.server_name = holder.take_server_name();
        }
        else if(id == "location"){
            server.yes_or_no.locations = true;
            std::string loc = holder.take_loc_path();
            holder.loction[loc] = take_location(holder);
            std::cout<<holder.am_here<<std::endl;
        }
        else if(id == "}")
            break;
        else
            print_eror("error");
    }
    std::cout<<"here"<<std::endl;
    if(server.yes_or_no.locations == true)
        server.loction = holder.loction;
    if(server.yes_or_no.cgi == true)
        server.cgi = holder.tmp;
    return server;
}
