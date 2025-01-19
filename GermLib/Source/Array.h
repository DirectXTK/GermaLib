#pragma once
#include <cstdlib>
#include <cstdint>
namespace Germ{

template<typename T,uint64_t inSize>
class Array{
    public:
        Array(){}
        T& operator[](uint64_t Index){
            return m_Data[Index];
        }
        uint64_t Size(){return inSize;}
    private:
        T m_Data[inSize];
};

}