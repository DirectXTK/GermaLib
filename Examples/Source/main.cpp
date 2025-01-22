#include "GermLib.h"
#include <iostream>
#include <string>
#include <stack>
void* operator new(std::size_t Size){
    printf("Allocation %i bytes\n",Size);
    return malloc(Size);
}
void operator delete(void* ptr,std::size_t size){
    printf("Deallocating %i bytes \n",size);
    free(ptr);
}
int main(){

    char strvar[100];
    /*
    Germ::Stack<std::string> lafa;
   // std::stack<std::string> lafa;
        lafa.Push("Pirmas");
        lafa.Push("Antras");
        lafa.Push("Trecias");
        lafa.Push("Ketvirtas");
        lafa.Push("Penktas");
        

    for(uint32_t i=0;i < 5;i++){
        printf("LAFA.top=%s\n",lafa.Top().c_str());
        lafa.Pop();
    }
    */
    Germ::String First("Pirmas");
    Germ::String Second("Antras");
    Germ::String Third("Trecias");

    Second= "Is tikra ne antrs";
    Third=First;

    printf("First=%s\n",First.C_str());
    printf("Second=%s\n",Second.C_str());
    printf("Third=%s\n",Third.C_str());



    fgets(strvar,100,stdin);
    return 0;
}