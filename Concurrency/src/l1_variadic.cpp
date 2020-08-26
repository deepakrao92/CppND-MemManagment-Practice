#include <iostream>
#include <thread>

void ID(int id)
{   
    std::cout << "Id is : " << id << std::endl;
}

void IDAndName(int id, std::string name)
{
    std::cout << "Id is: " << id << " and name is: " << name << std::endl;
}

int main()
{
    int id = 0;
    std::string name = "Some String";

    // Using variadic templates of the thread constructor
    std::thread t1(ID, ++id);
    std::thread t2(IDAndName, ++id, name);

    t1.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    t2.join();

    return 0;

}