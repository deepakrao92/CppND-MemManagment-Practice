#include <stdlib.h>
#include <iostream>

class MyClass
{
private:
    int *_number{0};
public:
    MyClass();
    ~MyClass();
    void SetNumber(int number);
};

MyClass::MyClass()
{
    std::cout << "Allocating " << sizeof(int) << " bytes of memory \n";
    _number = (int*)malloc(sizeof(int));
}

MyClass::~MyClass()
{
    std::cout << "Deallocating memory\n";
    free(_number);
}

void MyClass::SetNumber(int number){
    *_number = number;
    std::cout << "Setting number: " << *_number << std::endl;
}


int main(){

    // MyClass *object1 = (MyClass*)malloc(sizeof(MyClass));
    // object1->SetNumber(10);
    // free(object1);

    MyClass *object2 = new MyClass();
    object2->SetNumber(40);
    object2->~MyClass();
}