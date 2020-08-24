#include <iostream>

class NoCopyPrivate
{
private:
    NoCopyPrivate(NoCopyPrivate &object);
    NoCopyPrivate& operator=(NoCopyPrivate &object);
public:
    NoCopyPrivate(/* args */);
    ~NoCopyPrivate();
};

class NoCopyDelete
{
private:
    /* data */
public:
    NoCopyDelete(/* args */) {}
    NoCopyDelete(NoCopyDelete &object) = delete;
    ~NoCopyDelete() {}

    NoCopyDelete &operator=(NoCopyDelete &object) = delete;
};

int main(){
    NoCopyPrivate object1;
    NoCopyPrivate object2(object1);
    NoCopyPrivate object3 = object1;

    NoCopyDelete delete1;
    NoCopyDelete delete2(delete1);
    NoCopyDelete delete3 = delete1;
}