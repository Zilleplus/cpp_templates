#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits3.hpp"

template<typename T>
auto accum(T const* beg, T const* end)
{
    using Acct = typename AccumulationTraits<T>::AccT;

    Acct total = AccumulationTraits<T>::zero;
    while(beg!=end)
    {
        total += *beg;
        ++beg;
    }
}

#endif

