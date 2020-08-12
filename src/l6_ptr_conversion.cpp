#include <memory>
#include <iostream>

int main()
{
    std::unique_ptr<int> u_ptr = std::make_unique<int>(1);

    // From Unique to shared pointer
    std::shared_ptr<int> sh_ptr(std::move(u_ptr));

    // From shared to weak pointer
    std::weak_ptr<int> w_ptr(sh_ptr);

    // From weak to shared pointer
    std::shared_ptr<int> sh_ptr1 = w_ptr.lock();

    int *raw_ptr = sh_ptr1.get();
    delete raw_ptr;

    return 0;

}