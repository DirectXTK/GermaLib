#include <cstdint>
#include <xmemory>
#include <vector>
namespace Germ{

    template <typename T>
    class SharedPointer{
        public:

        T* GetData(){return m_Data;}
        uint32_t GetRefCount(){return *m_RefCount;}
        operator bool(){return m_RefCount == 0?false:true; }
        operator T*(){return m_Data;}
        SharedPointer(const SharedPointer& other){
            m_Data = other.m_Data;
            m_RefCount= other.m_RefCount;

            *m_RefCount+=1;
        }
        ~SharedPointer(){
            *m_RefCount-=1;
            if(*m_RefCount == 0){
                delete m_RefCount;
                delete m_Data;
            }
        }
        template <typename A>
        friend SharedPointer<A> MakeShared(A* Pointer);
    
        private:
           SharedPointer(T* Data)
        {
            m_RefCount = new uint32_t();
            m_Data = Data;
            *m_RefCount+=1;
        }
        uint32_t* m_RefCount{};
        T* m_Data{};
    };

    
    template<typename T,typename Alloc= std::allocator<T>>
    class UniquePointer{
        public:

        bool Empty(){return m_Data ==nullptr? true:false;}
        T* GetData(){return m_Data;}

        template<typename A,typename Alloc>
        friend UniquePointer<A,Alloc> MakeUnique(A* Pointer);

        operator bool(){return m_Data == nullptr ? false:true;}
        UniquePointer( UniquePointer& other)=delete;
        UniquePointer( UniquePointer&& other){
            m_Data = other.m_Data;
            other.m_Data = nullptr;
            printf("Moved\n");
        }

        ~UniquePointer(){
            Allocator.deallocate(m_Data,0);
            printf("Deleted\n");
        }
        private:
        UniquePointer(T* Pointer){
            m_Data = Pointer;
        }
        Alloc Allocator{};
        T* m_Data{};
    };
    template<typename T,typename Alloc= std::allocator<T>>
    UniquePointer<T,Alloc> MakeUnique(T* Pointer){
        return UniquePointer<T,Alloc>(Pointer);
    }
    template<typename T>
    SharedPointer<T> MakeShared(T* Pointer){
        return SharedPointer<T>(Pointer);
    }



}