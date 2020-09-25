#ifndef TUPLEEQ_HPP
#define TUPLEEQ_HPP

#include"tuple0.hpp"

// basis case:
bool operator ==(Tuple<> const& , Tuple<> const&)
{
    // empty tuples are always equivalent
    return true;
}

// this also seems simpler then the book version, it does require 
// the types of the tuple to match exactly. Otherwise the operator 
// is not defined, and error...
template<
    typename Head,
    typename... Tail
    >
bool operator ==(Tuple<Head, Tail...> const& left , Tuple<Head, Tail...> const& right)
{
    return left.getHead() == right.getHead()
        && left.getTail() == right.getTail();
}


#endif
