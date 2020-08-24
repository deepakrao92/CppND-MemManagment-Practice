#include <iostream>
#include <stdlib.h>

class DeepCopy
{
private:
    int *_number = 0;
public:
    DeepCopy(int val)
    {
        _number = (int*)malloc(sizeof(int));
        *_number = val;
        std::cout << "Resource allocated at " << _number << " having value of " << *_number << std::endl;
    }

    ~DeepCopy()
    {
        free(_number);
        std::cout << "Resource freed at " << _number << std::endl;
    }

    DeepCopy(DeepCopy &object){
        _number = (int*)malloc(sizeof(int));
        *_number = *object._number;
        std::cout << "Resource allocated at " << _number << " having value of " << *_number << std::endl;
    }

    DeepCopy &operator=(DeepCopy &object){
        _number = (int*)malloc(sizeof(int));
        *_number = *object._number;
        std::cout << "Resource allocated at " << _number << " having value of " << *_number << std::endl;
        return *this;
    }
};

int main()
{
    DeepCopy deepCopy1(42);
    DeepCopy deepCopy2(deepCopy1); // Copy constructor
    DeepCopy deepCopy3 = deepCopy2; // Asssignment operator

    return 0;
}