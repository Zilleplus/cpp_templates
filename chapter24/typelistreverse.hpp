#ifndef TYPELISTREVERSE_HPP
#define TYPELISTREVERSE_HPP

#include"typelistisempty.hpp"
#include"typelistfront.hpp"
#include"typelistpopfront.hpp"
#include"typelistpushback.hpp"

template<typename List, bool Empty = IsEmpty<List>::value>
class ReverseT;

template<typename List>
using Reverse = typename ReverseT<List>::Type;

// recursive case:
template<typename List>
class ReverseT<List,false>
{
    private: 
        using Head = Front<List>;
        using Tail = PopFront<List>;
        using NewTail = Reverse<Tail>;
    public:
        using Type = PushBack<NewTail, Head>;
};

// basis case
template<typename List>
class ReverseT<List,true>
{
    public:
        using Type = List;
};

#endif
