#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits4.hpp"
#include "sumpolicy1.hpp"

template<
    typename T,
    typename Policy = SumPolicy,
    typename Traits = AccumulationTraits<T>>
auto accum(T const* beg, T const* end)
{
    using Acct = typename Traits::AccT;
    Acct total = Traits::zero();
    while(beg != end){
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
}

#endif
