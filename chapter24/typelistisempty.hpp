#ifndef TYPELISTISEMPTY_HPP
#define TYPELISTISEMPTY_HPP

#include"typelist.hpp"

template<typename List>
struct IsEmpty{
    static constexpr bool value = false;
};

template<>
struct IsEmpty<Typelist<>>{
    static constexpr bool value = true;
};

#endif
