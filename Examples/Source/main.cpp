#include "GermLib.h"
#include "SmartPointers.h"
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <memory>
struct Custom{
    Custom(int input){
        lafa = new int();
        *lafa = input;
        printf("Number %i",*lafa);
    }
    int* lafa{};
    float* f1{};
   
};
template<typename T>
class CustomAlloc{
    public:

    using value_type = T;

    CustomAlloc() noexcept = default;

    Custom* allocate(uint64_t Size){
        return nullptr;
    }
    void deallocate(T* data,uint64_t Size){
        delete data->f1;
        delete data->lafa;
        printf("Custom alloc\n");
    }

    private:

};
void TestUnique(){
    int* number = new int();
    *number = 69;
   Germ::UniquePointer<Custom> uq = Germ::MakeUnique<Custom>(5);
}
void TestShared(){
  Germ::String First{"lafa"};
    int * lafa = new int();
    *lafa = 55;
    {
    Germ::SharedPointer<int> pointer = Germ::MakeShared<int>(lafa);

    std::cout << pointer.GetRefCount()<<"\n";

    Germ::SharedPointer l1 =pointer;
    std::cout << pointer.GetRefCount()<<"\n";
    {
    Germ::SharedPointer l3 =pointer;
    Germ::SharedPointer l4 =pointer;
    Germ::SharedPointer l5 =pointer;
    std::cout << pointer.GetRefCount()<<"\n";

    }
    std::cout << pointer.GetRefCount()<<"\n";

    std::cout << First;
    std::cout << *lafa<<"\n";
    }
    std::cout << *lafa;
}
int main(){

  TestUnique();


    return 0;
}