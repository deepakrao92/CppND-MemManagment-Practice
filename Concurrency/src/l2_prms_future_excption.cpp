#include <iostream>
#include <thread>
#include <future>

void Division(std::promise<double> &&prms, double num, double denom){
    try{
        if(denom == 0.0){
            throw std::runtime_error("Division by zero!");
        }
        else{
            prms.set_value(num/denom);
        }
    }
    catch(...){
        prms.set_exception(std::current_exception());
    }
}

int main(){
    double num = 16;

    // Create promise and future
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    // Create thread and pass value
    std::thread t1(Division, std::move(prms), num, 0);

    try{
        int result = ftr.get();
        std::cout << "Result of division is: " << result;
    }
    catch(std::runtime_error e){
        std::cout << e.what() << '\n';
    }
    
    t1.join();

    return 0;
}