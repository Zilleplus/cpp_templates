#ifndef LARGESTTYPEACC0_HPP
#define LARGESTTYPEACC0_HPP

#include"ifthenelse.hpp"
#include"typelistfront.hpp"
#include"accumulate.hpp"
#include"typelistpopfront.hpp"

template<typename T, typename U>
struct LargerTypeT : public IfThenElseT<sizeof(T) >= sizeof(U), T, U>
{
};

template<typename TypeList>
struct LargestTypeAccT
    : public AccumulateT<PopFront<TypeList>, LargerTypeT, Front<TypeList>>
{};

template<typename TypeList>
using LargerTypeAcc = typename LargestTypeAccT<TypeList>::Type;

#endif
