#include <iostream>

class RuleThree
{
private:
    int* _data;
    int _size;
public:
    RuleThree(size_t size) // Default constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "Created first instance of object at " << _data << " with a size of " << _size*sizeof(int) << " bytes" << std::endl;
    }
    
    ~RuleThree() // 1: Destructor
    {
        delete _data;
        std::cout << "Deleted object at " << _data << std::endl;
    }

    RuleThree(const RuleThree &source) // 2: Copy Constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "Copied object at " << _data << " with a size of " << _size*sizeof(int) << " bytes" << std::endl;
    }

    RuleThree &operator=(const RuleThree &source) // 3: Copy Assignment Operator
    {
        _size = source._size;
        if(this == &source)
            return *this;
        delete _data;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "Assigned source object to destination object at " << _data << " with a size of " << _size*sizeof(int) << " bytes" << std::endl;

        return *this;
    }

};

int main(){

    RuleThree source(5);
    RuleThree dest1(source);
    dest1 = source;

}