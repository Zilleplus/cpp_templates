#ifndef LARGESTTYPEACC_HPP
#define LARGESTTYPEACC_HPP

#include"ifthenelse.hpp"
#include"typelistisempty.hpp"
#include"typelistfront.hpp"
#include"typelistpopfront.hpp"
#include"accumulate.hpp"

template<typename T, typename U>
struct LargerTypeT
: public IfThenElseT<sizeof(T) >= sizeof(U), T, U>
{
};

template<typename Typelist, bool = IsEmpty<Typelist>::value>
struct LargerTypeAccT;

template<typename Typelist>
struct LargerTypeAccT<Typelist, false>
: public AccumulateT<PopFront<Typelist>, LargerTypeT, Front<Typelist>>
{
};

template<typename Typelist>
struct LargerTypeAccT<Typelist, true>
{
};

template<typename Typelist>
using LargerTypeAcc = typename LargerTypeAccT<Typelist>::Type;

#endif
