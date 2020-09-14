#ifndef TYPELISTPOPBACK_HPP
#define TYPELISTPOPBACK_HPP

#include"typelistreverse.hpp"

template<typename List>
struct PopBackT{
    using Type = Reverse<PopFront<Reverse<List>>>;
};

template<typename List>
using PopBack = typename PopBackT<List>::Type;

#endif
