#ifndef NTHELEMENT_HPP
#define NTHELEMENT_HPP

#include"typelistpopfront.hpp"
#include"typelistfront.hpp"

template<typename List, unsigned N>
struct NthElementT : public NthElementT<PopFront<List>,N-1>
{
};

template<typename List>
struct NthElementT<List,0> : public Front<List>
{
};

template<typename List, unsigned N>
using NthElement = typename NthElementT<List,N>::Type;

#endif
