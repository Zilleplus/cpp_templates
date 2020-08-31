#include"issame.hpp"
#include<iostream>

// This technique is called tag dispatching !

template<typename T>
void fooImpl(T, TrueType)
{
    std::cout << "goodImpl(T,true) for int called" << std::endl;
}

template<typename T>
void fooImpl(T, FalseType)
{
    std::cout << "goodImpl(T,false) for int called" << std::endl;
}

template<typename T>
void foo(T t)
{
    fooImpl(t, IsSameT<T,int>{});
}

int main()
{
    foo(42);
    foo(7.7);
}
