#ifndef TYPELISTFRONT_HPP
#define TYPELISTFRONT_HPP

#include "typelist.hpp"

template<typename List>
struct FrontT;

template<typename HEAD, typename... Tail>
struct FrontT<Typelist<HEAD,Tail...>>{
    using Type = HEAD;
};

template<typename List>
using Front = typename FrontT<List>::Type;

#endif
