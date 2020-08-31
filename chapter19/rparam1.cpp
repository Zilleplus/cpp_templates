#include "rparam.hpp"
#include "rparamcls.hpp"

// function that allows parameter passing by value or by reference
template<typename T1, typename T2>
void foo(typename RParam<T1>::Type p1,
         typename RParam<T2>::Type p2)
{
    std::cout << "foo called" << std::endl;
}

int main()
{
    MyClass1 mc1;
    MyClass2 mc2; // copy ctor is called as their is a specialization in rparamcls.hpp
    foo<MyClass1,MyClass2>(mc1,mc2);
}

