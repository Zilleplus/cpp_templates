#ifndef RPARAM_HPP
#define RPARAM_HPP

#include"ifthenelse.hpp"
#include<type_traits>

template<typename T>
struct RParam{
    // If it's possible to move/copy and it's small enought -> pass by value
    using Type 
        = IfThenElse<(sizeof(T) <= 2*sizeof(void*)
                && std::is_trivially_copy_constructible<T>::value
                && std::is_trivially_move_constructible<T>::value),
        T,
        T const&>;
};

#endif
