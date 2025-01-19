#pragma once
#include <cstdint>

namespace Germ{
template<typename T,uint64_t Size>
class Array{
    public:
        Array();
        T& operator[](uint64_t Index){
            return m_Data[Index];
        }
        uint64_t Size(){return Size;}
    private:
        T m_Data[Size];
};
}