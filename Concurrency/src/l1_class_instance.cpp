#include <thread>
#include <iostream>

class Vehicle
{
private:
    int _id;
public:
    void operator()()
    {
        std::cout << "Vehicle #" << _id <<  " created\n";
    }
    Vehicle(int id) : _id(id) {}
};

int main()
{
    // Create thread
    std::thread v1 = std::thread(Vehicle(1));

    // Do Something in main
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Wait for thread to finish
    v1.join();
    
    return 0;
}