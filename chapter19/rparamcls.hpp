#include "rparam.hpp"
#include <iostream>

class MyClass1{
    public:
        MyClass1(){}

        MyClass1(MyClass1 const&){
            std::cout << "MyClass1 copy constructor called" << std::endl;
        }
};

class MyClass2{
    public:
        MyClass2(){}

        MyClass2(MyClass2 const&){
            std::cout << "MyClass2 copy constructor called" << std::endl;
        }
};


template<>
class RParam<MyClass2>
{
    public:
        using Type = MyClass2;
};
