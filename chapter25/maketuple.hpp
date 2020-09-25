#ifndef MAKETUPLE_HPP 
#define MAKETUPLE_HPP

#include<type_traits>
#include<utility>
#include"tuple0.hpp"

template<typename... Types>
auto makeTuple(Types&&... elems)
{
    return Tuple<std::decay_t<Types>...>
        (std::forward<Types>(elems)...);
}

#endif
