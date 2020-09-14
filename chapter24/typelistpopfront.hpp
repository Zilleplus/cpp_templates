#ifndef TYPELISTPOPFRONT_HPP
#define TYPELISTPOPFRONT_HPP

#include"typelist.hpp"

template<typename List>
struct PopFrontT;

template<typename Head, typename... Tail>
struct PopFrontT<Typelist<Head, Tail...>>{
    using Type = Typelist<Tail...>;
};

template<typename List>
using PopFront = typename PopFrontT<List>::Type;

#endif
