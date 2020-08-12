#include <iostream>
#include <memory>

class Transfer
{
private:
    int _number;
public:
    Transfer(int n)
    {
        _number = n;
    }
    ~Transfer() {}

    void printVal()
    {
        std::cout << ", (heap) object at " << this << " having a value of " << _number << std::endl;
    }
};

void Func(std::unique_ptr<Transfer> ptr)
{   
    std::cout << "Unique pointer at (stack) " << &ptr;
    ptr->printVal();
}

int main()
{
    std::unique_ptr<Transfer> unique_ptr = std::make_unique<Transfer>(10);
    std::cout << "Unique pointer at (stack) " << &unique_ptr;
    unique_ptr->printVal();

    Func(std::move(unique_ptr));

    if (unique_ptr)
        unique_ptr->printVal();
    return 0;
}