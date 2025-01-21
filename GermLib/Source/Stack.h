#pragma once
#include <cstdint>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
namespace Germ{

    template<typename T>
    class Stack{
    public:
    #define InitSize 256
        Stack(){
            Resize(InitSize);
        }
        void Push(const T& Data){
            if(m_Size+1 >m_Capacity)
                Resize(m_Capacity+InitSize);
            // m_Data[m_Size]=T();   
            m_Data[m_Size] = Data;
            m_Size++;
        }
        void Pop(){
            m_Size--;
            if(m_Capacity/m_Size >=1.1f&&m_Capacity != 256)
                Resize(m_Capacity-InitSize);
        }
        T& Top(){
            return m_Data[m_Size-1];
        }
        uint64_t Size(){return m_Size;}
        ~Stack(){
            delete[] m_Data;
        }
    private:
        void Resize(uint64_t NewSize){
            T* NewData = new T[NewSize];
            memcpy(NewData,m_Data,sizeof(T)*m_Size);
            for(uint64_t i =0;i < m_Size;i++){
                //NewData[i] = T();
                //NewData[i] = m_Data[i];
            }

            delete[] m_Data;
            m_Data = NewData;
            printf("Blogai %i\n",NewSize);
            m_Capacity = NewSize;
        }
        uint64_t m_Size{};
        uint64_t m_Capacity{};
        T* m_Data{};
    };
}