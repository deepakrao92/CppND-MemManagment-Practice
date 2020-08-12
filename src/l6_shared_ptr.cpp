#include <iostream>
#include <memory>

class SharedPtr
{
public:
    SharedPtr() {
        std::cout << "Shared Pointer created at " << this << std::endl;
    }
    ~SharedPtr() {
        std::cout << "Destructor called !\n";
    }
};

void getCount(std::shared_ptr<SharedPtr> &ptr)
{
    std::cout << "Count is: " << ptr.use_count() << " pointing at " << ptr.get() << std::endl;
}

int main()
{
    std::shared_ptr<SharedPtr> ptr1(new SharedPtr);
    getCount(ptr1);
    
    {
        std::shared_ptr<SharedPtr> ptr2 = ptr1;
        getCount(ptr1);
        {
        std::shared_ptr<SharedPtr> ptr3(ptr1);
        getCount(ptr1);
        std::cout << "Stack address of pointers are " << ptr1.get() << " , " << ptr2.get() << " and " << ptr2.get() << std::endl;
        }
        getCount(ptr1);    
    }
    
    getCount(ptr1);

    return 0;
}