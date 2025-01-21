#include "GermLib.h"
#include <iostream>
#include <stack>
#include <string>
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

    fgets(strvar,100,stdin);
    return 0;
}