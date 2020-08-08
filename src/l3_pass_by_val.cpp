#include <iostream>

void AddTwoVal(int val)
{
    val += 2;
}

void AddTwoPointer(int *val)
{
    *val += 2;
}

void AddTwoRef(int &val)
{
    val += 2;
}

int main()
{
    int val = 0;
    AddTwoVal(val);
    val += 2;
    std::cout << "Passing by Value: \nExpected Value: 4, Actual Value: " << val << std::endl;

    val = 0;
    AddTwoPointer(&val);
    val += 2;
    std::cout << "Passing address: \nExpected Value: 4, Actual Value: " << val << std::endl;
  

    val = 0;
    AddTwoRef(val);
    val += 2;
    std::cout << "Passing by Reference: \nExpected Value: 4, Actual Value: " << val << std::endl;

    return 0;
}