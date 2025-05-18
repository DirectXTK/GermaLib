#pragma once

#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <ostream>
namespace Germ{

class String{
    public:
        String(const char* str){
            Resize(strlen(str)+1);
            m_Size = strlen(str)+1;
            memcpy(m_Data,str,sizeof(char)*m_Size);
        }
        String(){}

        void Resize(uint64_t NewSize){
            char* OldData = m_Data;
            m_Data = new char[NewSize];
            memcpy(m_Data,OldData,sizeof(char)*m_Size);

            delete[] OldData;
            m_Capacity = NewSize;
        }
        String& operator=(const String& other){
            if(other.m_Capacity >m_Capacity){
                Resize(other.m_Capacity);
            }
            memcpy(m_Data,other.m_Data,m_Capacity);
            m_Size = other.m_Size;
            return *this;
        }
          String& operator=(const char* other){
            uint64_t StrSize = strlen(other)+1;
            if(StrSize>m_Capacity){
                Resize(StrSize);
            }
            memcpy(m_Data,other,m_Capacity);
            m_Size =StrSize;
            return *this;
        }

        const char* C_str(){return m_Data;}
        void* Data(){return m_Data;}
        uint64_t Size(){return m_Size;}
        uint64_t Capacity(){return m_Capacity;}

        ~String(){
            delete[] m_Data;
        }

    private:
     friend std::ostream& operator<<(std::ostream& os,const Germ::String& string){
         os << string.m_Data;
         return os;
        }
        
    uint64_t m_Size{};
    uint64_t m_Capacity{};
    char* m_Data{};
};
    


}
