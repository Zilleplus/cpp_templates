#ifndef TUPLEIO_HPP
#define TUPLEIO_HPP

#include<iostream>
#include"tuple0.hpp"

void printTuple(std::ostream& strm, Tuple<> const&, bool isFirst = true)
{
    strm << ( isFirst ? '(' : ')');
}

template<typename Head, typename... Tail>
void printTuple(std::ostream& strm, Tuple<Head, Tail...> const& t, bool isFirst = true)
{
    strm << ( isFirst ? '(' : ',');
    strm << ( t.getHead() );
    printTuple(strm, t.getTail(), false);
}

template<typename... Types>
std::ostream& operator<<(std::ostream& strm, Tuple<Types...> const& t)
{
    printTuple(strm, t);
    return strm;
}

#endif
