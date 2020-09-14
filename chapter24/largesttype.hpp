#ifndef LARGESTTYPE_HPP
#define LARGESTTYPE_HPP

#include "typelist.hpp"
#include "typelistfront.hpp"
#include "typelistpopfront.hpp"
#include "ifthenelse.hpp"

template<typename List>
struct LargestTypeT;

// recursive case:
template<typename List>
class LargestTypeT
{
    using First = Front<List>;
    using Rest = typename LargestTypeT<PopFront<List>>::Type;
public:
    using Type = IfThenElse<(sizeof(First) >= sizeof(Rest)), First, Rest>;

};

template<>
class LargestTypeT<Typelist<>>
{
    public:
        using Type = char;
};

#endif
