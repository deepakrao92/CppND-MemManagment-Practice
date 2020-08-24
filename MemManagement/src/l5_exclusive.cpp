#include <iostream>

class ExclusiveCopy
{
private:
    int* _number;
public:
    ExclusiveCopy()
    {
        _number = (int*)malloc(sizeof(int));
        std::cout << "Resource allocated first time." << std::endl;
    }
    
    ~ExclusiveCopy()
    {
        if(_number != nullptr)
        {
            free(_number);
            std::cout << "Resource was freed" << std::endl;
        }
    }

    ExclusiveCopy(ExclusiveCopy &source)
    {
        _number = source._number;
        source._number = nullptr;
        std::cout << "Copied!\n";
    }
    ExclusiveCopy &operator=(ExclusiveCopy &source)
    {
        _number = source._number;
        source._number = nullptr;
        return *this;
    }
};


int main(){

    ExclusiveCopy obj1, obj3;
    ExclusiveCopy obj2(obj1);
    obj3 = obj2;
}
