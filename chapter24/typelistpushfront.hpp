#ifndef TYPELISTPUSHFROND_HPP
#define TYPELISTPUSHFROND_HPP

#include"typelist.hpp"

template<typename List, typename NewElement>
struct PushFrontT;

template<typename... Elements, typename NewElement>
struct PushFrontT<Typelist<Elements...>,NewElement>{
    using Type = Typelist<NewElement, Elements...>;
};

template<typename Elements, typename NewElement>
using PushFront = typename PushFrontT<Elements, NewElement>::Type;

#endif
