#include <thread>
#include <iostream>

int main()
{
    std::cout << "Hello Multi-threading world, I am the main thread having id : " << std::this_thread::get_id() << std::endl;
    
    std::cout << "The number of cores available on this machine are: " << std::thread::hardware_concurrency() << std::endl;
}