#ifndef SELECT_HPP
#define SELECT_HPP

#include"valuelist.hpp"
#include"nthelement.hpp"

template<typename Types, typename Indices>
struct SelectT;

template<typename Types, unsigned... Indices>
struct SelectT<Types, Valuelist<unsigned, Indices...>>
{
    using Type = Typelist<NthElement<Types, Indices>...>;
};

#endif
