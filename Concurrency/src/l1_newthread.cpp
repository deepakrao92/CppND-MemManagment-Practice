#include <thread>
#include <iostream>

// IMPORTANT: Compile this with flag -pthread

void DoSomething()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Finished worker thread task\n";
}

int main()
{
    // Create a thread
    std::thread firstThread(DoSomething);

    //
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Main Thread tasks over\n";

    // Waiting for worker thread to finish
    firstThread.join();

    return 0; 
}