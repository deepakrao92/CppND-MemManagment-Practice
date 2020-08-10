#include <stdlib.h>
#include <iostream>

class OverloadEx
{
private:
    /* data */
public:
    OverloadEx();
    ~OverloadEx();
    void* operator new(size_t size){
        void *p = malloc(size);
        return p;
    }

    void operator delete(void* p){
        free(p);
    }

};

OverloadEx::OverloadEx(/* args */)
{
    std::cout << "Constructor called!" << std::endl;
}

OverloadEx::~OverloadEx()
{
    std::cout << "Destructor called!" << std::endl;
}


int main(){

    OverloadEx *myObj = new OverloadEx();
    myObj->~OverloadEx();

}