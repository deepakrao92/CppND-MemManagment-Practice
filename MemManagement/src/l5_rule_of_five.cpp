#include <iostream>

class MovableClass
{
private:
    int _size;
    int *_data;
public:
    MovableClass(size_t size) 
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATED     object at " << this << " with memory of " << _size*sizeof(int) << " bytes." << std::endl;
    }
    
    ~MovableClass() // 1: Destructor
    {
        delete[] _data;
        std::cout << "DELETED     object at " << this << std::endl;
    }

    MovableClass(MovableClass &source) // 2: Copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPIED      object from " << &source << " to the instance at " << this << std::endl;
    }

    MovableClass &operator=(MovableClass &source) // 3: Copy Assignment Operator
    {
        if (this == &source) // Protection against self assignment
            return *this;

        delete[] _data;
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "ASSIGNED    object from " << &source << " to the instance at " << this << std::endl;
        return *this;
    }

    MovableClass(MovableClass &&source) // 4: Move constructor
    {
        _size = source._size;
        _data = source._data;
        std::cout << "MOVED (ctr) object from " << &source << " to the instance at " << this << std::endl;
        source._data = nullptr;
        source._size = 0;
    }

    MovableClass &operator=(MovableClass &&source) // 5: Move assignment operator
    {
        if (this == &source)
            return *this;

        delete[] _data;
        _data = source._data;
        _size = source._size;
        std::cout << "MOVED (asn) object from " << &source << " to the instance at" << this << std::endl;
        source._size = 0;
        source._data = nullptr;
        return *this;
    }
};

int main(){
    MovableClass source(10);        // Default Constructor
    // MovableClass dest1(source);     // Copy Constructor
    // dest1 = source;                 // Copy Assignment Operator

    // MovableClass dest2 = MovableClass(20); // Move Constructor
    source = MovableClass(30);

    MovableClass dest2(std::move(source));

    return 0;
}