#include <iostream>
#include "kv_store.hpp"

int main(){
    KVStore store;
    store.set("name", "thomas");

    auto v= store.get("name");
    if(v){
        std::cout <<"name = " <<*v << "\n";
    }
    else{
        std::cout << "not found \n";
    }

    if (!store.get("missing")){
        std::cout << "missing -> not found \n";
    }
}