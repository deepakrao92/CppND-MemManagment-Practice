#include <iostream>
#include <string>
#include <memory>

class UniquePtrClass
{
private:
    std::string _name;
    int _age;

public:
    UniquePtrClass() {}
    UniquePtrClass(std::string name, int age);
    ~UniquePtrClass();
    void setAge(int age);
    void setName(std::string name);
    std::string getName()
    {
        return _name;
    }
    int getAge();
    long salary;
};

UniquePtrClass::UniquePtrClass(std::string name, int age)
{
    _name = name;
    _age = age;
}

UniquePtrClass::~UniquePtrClass()
{
    std::cout << "Destructor called!\n";
}

void UniquePtrClass::setAge(int age)
{
    _age = age;
}

void UniquePtrClass::setName(std::string name)
{
    _name = name;
}

int UniquePtrClass::getAge()
{
    return _age;
}


int main()
{
    std::unique_ptr<UniquePtrClass> student1(new UniquePtrClass());
    std::unique_ptr<UniquePtrClass> student2(new UniquePtrClass("Alpha", 27));

    student1->setAge(25);
    student1->setName(student2->getName());

    std::cout << student1->getName() << " aged " << student1->getAge() << " lives at " << student1.get() << std::endl;
    std::cout << student2->getName() << " aged " << student2->getAge() << " lives at " << student2.get() << std::endl;

    student1->setName("Eric");
    student1->setAge(30);
    *student2 = *student1;

    std::cout << student1->getName() << " aged " << student1->getAge() << " lives at " << student1.get() << std::endl;
    std::cout << student2->getName() << " aged " << student2->getAge() << " lives at " << student2.get() << std::endl;



}