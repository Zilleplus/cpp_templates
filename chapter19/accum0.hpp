#ifndef ACCUM_HPP
#define ACCUM_HPP

#include<iterator>

template<typename Iter>
auto accum(Iter start, Iter stop)
{
    using VT = typename std::iterator_traits<Iter>::value_type;


    VT total{};
    while(start != stop)
    {
        total += *start;
        ++start;
    }
    return total;
}

#endif
