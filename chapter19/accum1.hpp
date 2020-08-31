#ifndef ACCUM_HPP
#define ACCUM_HPP

template<typename T>
T accum (T const* beg, T const* end)
{
    T total{};
    while(beg !=end)
    {
        total += *beg;
        ++beg;
    }
    
    return total;
}

#endif

