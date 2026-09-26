#include <iostream>
#include <string>
#include "kv_store.hpp"

int main(){
    KVStore store;
    std::string line;
    // store.set("name", "thomas");
    while (true){
        std::cout << ">";
        if (!std::getline(std::cin, line)){
            break;
        }

        if (line == "QUIT"){
            break;
        }
        std::string command, rest;
        size_t space_pos = line.find (' ');
        if (space_pos == std::string::npos){
            command = line;
            rest = "";
        } else{
            command = line.substr(0,space_pos);
            rest = line.substr(space_pos+1);
        }

        if (command =="SET"){
            size_t kv_space = rest.find (' '); 
            if (kv_space == std::string::npos){
                std::cout << "error, no value" << std::endl;
            } else{
                std::string key = rest.substr(0,kv_space);
                std::string value = rest.substr(kv_space +1);
                store.set(key,value);
                std::cout << "OK" <<std::endl;
            }
        }
        if (command =="GET"){
            auto v = store.get(rest); //key from my kv_store.hpp key in the map
            if (v){
                std::cout << *v << std::endl;
            } else{
                std::cout << "not found" << std::endl;
            }
        }
        if (command == "DEL"){
            bool result = store.del(rest);
            if(result){
                std::cout <<"Entry deleted" << std::endl;
            } else{
                std::cout << "No entry found" << std::endl;
            }
        }
    }
}