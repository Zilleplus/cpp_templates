#include "rparam.hpp"
#include "rparamcls.hpp"

// Function that allows parameter passing by value or by reference.
template<typename T1, typename T2>
void foo_core(
        typename RParam<T1>::Type p1,
        typename RParam<T2>::Type p2)
{
    std::cout << "foo_core called" << std::endl;
}

// Workaround to not have to specify the types when calling.
template<typename T1, typename T2>
void foo(T1 && p1, T2 && p2)
{
    foo_core<T1,T2>(std::forward<T1>(p1),std::forward<T2>(p2));
}

int main()
{
    MyClass1 mc1;
    MyClass2 mc2;
    foo(mc1,mc2);
}

