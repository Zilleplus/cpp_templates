#ifndef ACCUMULATE_HPP
#define ACCUMULATE_HPP

#include"typelist.hpp"
#include"typelistpopfront.hpp"
#include"typelistfront.hpp"
#include"typelistisempty.hpp"

template<typename List,
    template<typename X, typename Y> class F,
    typename I,
    bool = IsEmpty<List>::value>
struct AccumulateT;

template<typename List, template<typename X, typename Y> class F, typename I>
struct AccumulateT<List,F,I,false> 
    : public AccumulateT<
        PopFront<List>,
        F,
        typename F<I,Front<List>>::Type>
{
};

// basis case:
template<typename List,
    template<typename X, typename Y> typename F,
    typename I>
struct AccumulateT<List,F,I,true>
{
    using Type = I;
};

template<typename List,
    template<typename X, typename Y> typename F,
    typename I>
using Accumulate = AccumulateT<List,F,I>;

#endif
