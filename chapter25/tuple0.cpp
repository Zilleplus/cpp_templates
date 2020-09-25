#include"tuple0.hpp"
#include"tupleget.hpp"
#include"tupleeq.hpp"
#include<iostream>
#include"tupleio.hpp"

int main()
{
    auto intDouble = Tuple<int,double>(2,1.1);
    auto intDouble_double = get<1>(intDouble);

    auto duplicate = Tuple<int,double>(2,1.1);
    bool test = intDouble == duplicate;

    std::cout << intDouble << std::endl;
}
