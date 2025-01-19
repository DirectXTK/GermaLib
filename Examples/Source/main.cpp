#include "GermLib.h"
#include <iostream>
#include <string>
#include <unordered_map>
int main(){

    char strvar[100];
    std::unordered_map<std::string,int> map{};
    std::string a;

    a = "lafa";
    Germ::Array<int,5> Array;

    for(uint32_t i=0;i < 5;i++){
        Array[i] = i*30;
        printf("Array[%i]=%i",i,Array[i]);
    }

    map["Vytas"] = 20;
    map["Gabuks"]= 21;
    map["Pusbrolys"]=22;

    for(auto it = map.begin();it != map.end();it++){
        printf("%s = %i",it->first.c_str(),it->second);
    }
    //cout and cin notworking

    fgets(strvar,100,stdin);
    return 0;
}