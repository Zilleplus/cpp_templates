#ifndef TYPELISTPUSHBACK_HPP
#define TYPELISTPUSHBACK_HPP

#include"typelist.hpp"

// In the text the parameter pack is the first element
// this fails with the clang++ compiler. As parameter
// packs should alway's be the last template parameter.
template<typename NewElement, typename... Elements>
struct PushBackT;

// here we can put it first, as it's a specialization
template<typename... Elements, typename NewElement>
struct PushBackT<Typelist<NewElement,Elements...>>{
    using Type = Typelist<Elements...,NewElement>;
};

template<typename NewElement, typename... Elements>
using PushBack = typename PushBackT<NewElement,Elements...>::Type;

#endif
