#ifndef RATIOADD_HPP
#define RATIOADD_HPP

#include"ratio.hpp"

template<typename R1, typename R2>
struct RatioAddImpl{
    private:
        static constexpr unsigned num = R1::den * R2::den;
        static constexpr unsigned den = R1::num * R2::den + R2::num * R1::den;
    public:
        using Type = Ratio<num,den>;
};

template<typename R1, typename R2>
using RatioAdd = typename RatioAddImpl<R1,R2>::Type;

#endif
