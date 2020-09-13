#ifndef DURATION_HPP
#define DURATION_HPP

#include"ratio.hpp"

template<typename T, typename U = Ratio<1>>
class  Duration{
    public:
        using ValueType = T;
        using UnitType = typename U::Type;
    private: 
        ValueType val;
    public:
        constexpr Duration(ValueType v = 0)
            : val(v){
        }

        constexpr ValueType value() const {
            return val;
        }
};

#endif
