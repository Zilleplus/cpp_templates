#ifndef INSERTIONSORTTEST_HPP
#define INSERTIONSORTTEST_HPP

#include "insertionsort.hpp"
#include <iostream>
#include <type_traits>

template<typename T, typename U>
struct SmallerThanT{
    static constexpr bool value = sizeof(T) < sizeof(U);
};

void testInsertionSlot()
{
    using Types = Typelist<int, char, short, double>;
    using ST = InsertionSort<Types,SmallerThanT>;
    std::cout 
        << std::is_same<ST, Typelist<char, short, int, double>>::value 
        << std::endl;
}

#endif
