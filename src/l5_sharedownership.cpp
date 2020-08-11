#include <stdlib.h>
#include <iostream>

class Shared
{
private:
    int *_nummer{0};
    static int _cnt;
public:
    Shared(int val)
    {
        _nummer = (int*)malloc(sizeof(int));
        *_nummer = val;
        ++_cnt;
        std::cout << "Resource allocated at " << _nummer << " having a value of " << *_nummer << ", counter is " << _cnt << std::endl;
    }
    ~Shared()
    {
        --_cnt;
        if(_cnt == 0)
        {
            free(_nummer);
            std::cout << "Resource freed at " << _nummer << ", counter is " << _cnt << std::endl;
        }
        else
        {
            std::cout << "Resource at " << this << " goes out of scope, counter value is " << _cnt << std::endl;
        }
    }
        
    Shared(Shared &object)
    {
        _nummer = object._nummer;
        ++_cnt;
        std::cout << _cnt << " instances with handle to address " << _nummer << " with value " << *_nummer << std::endl;
    }

    Shared &operator=(Shared &object)
    {
        _nummer = object._nummer;
        ++_cnt;
        std::cout << _cnt << " instances with handle to address " << _nummer << " with value " << *_nummer << std::endl;
        return *this;
    }
        
};

// counter is declared as a static variable so that counter value persists and not initialised for each instance
int Shared::_cnt = 0;

int main()
{
    Shared source{10};
    Shared dest1(source); // Copy constructor
    Shared dest2(source); // Copy constructor
    Shared dest3 = source; // Assignment operator

    return 0;
}

