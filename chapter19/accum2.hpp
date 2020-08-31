#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits2.hpp"

template<typename T>
auto accum(T const* beg, T const* end)
{
    using Acct = typename AccumulationTraits<T>::AccT;

    Acct total{};
    while(beg!=end)
    {
        total += *beg;
        ++beg;
    }
}

#endif

