#include <thread>
#include <iostream>

void printMsg(std::string msg)
{
    std::cout << "Received message is: " << msg << std::endl;
}

int main()
{
    std::string msg = "Some message";

    // Send data from parent to worker thread using variadic templates
    std::thread t1{printMsg, msg};

    // Send data from parent to worker thread using lambdas
    std::thread t2(
        [msg]() {std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "thread 2 has message: " << msg << std::endl;}
    );

    t1.join();
    t2.join();

    return 0;

    
}