#include <iostream>

int main()
{
int var = 0;
    // Lambda declaration [] --> Capture list, () --> parameter list, {} --> Main part
    //  auto f0 = []() {std::cout << "Variable is: " << var << std::endl;}; // By default, the varibles outside the {} 
                                                                            // of Lambda main can't be accessed --> Error
                                                                            // By listing them in the capture list, they can be accessed
                                                                            // as in next 

    ++var;
    // Declare var in capture list so that main can access it & pass by value
    auto f1 = [var]() {std::cout << "Variable is: " << var << std::endl;};
    
    ++var;
    // Declare var in capture list so that main can access it & pass by value
    auto f2 = [&var]() {std::cout << "Variable is : " << var << std::endl;};
    
    // auto f3 = [var](){std::cout << "Variable is: " << ++var << std::endl;};  // error as variables can't be modified 
                                                                                // unless declared as mutable
    auto f4 = [var]() mutable {std::cout << "Variable is changed to: " << ++var << std::endl;};

    f1();    
    f2();
    f4();

    // Pass a parameter
    auto f5 = [] (const int id) { std::cout << "Value of passed variable is: " << id << std::endl;};
    f5(var);

    return 0;
}