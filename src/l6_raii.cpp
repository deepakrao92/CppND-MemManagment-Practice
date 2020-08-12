#include <iostream>

class RAII
{
private:
    int *_p;
public:
    RAII(int *p = NULL)
    {
        _p = p;
    }
    
    ~RAII() 
    {
        delete _p;
    }

    int &operator*()
    {
        return *_p;
    }
};

int main(){

    double arr[] = {1.0,2.0,3.0,4.0,5.0};

    for (int i = 0; i < 5; i++)
    {
        //Allocate resource on the heap
        RAII j(new int(i));

        //Division
        std::cout << *j << "/" << arr[i] << " = " << *j/arr[i] << std::endl;
    }

    return 0;

}