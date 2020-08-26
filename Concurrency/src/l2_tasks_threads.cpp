#include <iostream>
#include <thread>
#include <future>

double Division(double num, double denom){
    
    if (denom == 0)
        throw std::runtime_error("Exception: Division by zero!");

    return num/denom;
}

// Compared to the promise and future, async handles a lot of the stuff similar to code in promises and future
// 

int main(){
    double num = 16;
    double denom = 0;
    // Create a future object
    std::future<double> ftr = std::async(Division, num, denom);

    try{
        double result = ftr.get();
        std::cout << "Result of division is: " << result << std::endl;
    }
    catch(std::runtime_error e){
        std::cout << e.what() << '\n';
    }
    
    // t1.join(); No need to explicityl call the join method as async destructor will handle it

    return 0;
}