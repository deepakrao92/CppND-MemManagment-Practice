#include <thread>
#include <future>
#include <iostream>

void ModifyMsg(std::promise<std::string> &&prms, std::string msg)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    msg += " has been modified in worker thread";
    prms.set_value(msg);
}

int main()
{
    std::string sentMsg = "Main message";

    // Create a promise and future object
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // Create thread
    std::thread thr{ModifyMsg, std::move(prms), sentMsg};

    std::cout << "Message from main: " << sentMsg << std::endl;

    std::string returnMsg = ftr.get();
    std::cout << "Message received from thread: " << returnMsg << std::endl;


    thr.join();

    return 0;
}