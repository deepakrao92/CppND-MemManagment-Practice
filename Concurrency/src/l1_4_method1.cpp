#include <thread>
#include <iostream>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle created\n";
    }
};

int main()
{
    // Create thread object
    // std::thread thread1(Vehicle()); // This results in error due to C++ vexing parse
    // There is an ambiguity as the compiler can treat this as a variable thread1 of type thread, initialized with class instance
    // or
    // function declaration with return type of thread and an argument 

    // Force complier to interpret it as a variable by one of these 3 methods

    // 1. Add an extra pair of parentheses
    std::thread t1( (Vehicle()) );

    // 2. Use copy initialization
    std::thread t2 = std::thread(Vehicle());

    // 3. Use uniform initialization with braces
    std::thread t3{Vehicle()};

    // Do Something in main
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Wait for thread to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}