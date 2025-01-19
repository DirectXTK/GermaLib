#include "GermLib.h"
#include <iostream>

int main(){
    uint32_t ArraySize{5};
    Germ::Array<int,ArraySize> Array{};
    for(uint32_t i=0;i < ArraySize;i++){
        Array[i] = i*30;
        printf("Array[%i]=%i",i,Array[i]);
    }

    return 0;
}