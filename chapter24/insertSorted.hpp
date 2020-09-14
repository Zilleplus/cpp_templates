#ifndef INSERTSORTED_HPP
#define INSERTSORTED_HPP

#include "identity.hpp"
#include "typelistisempty.hpp"
#include "typelistfront.hpp"
#include "typelistpopfront.hpp"
#include "typelistpushfront.hpp"
#include "ifthenelse.hpp"

template<typename List, typename Element,
    template<typename T, typename U> typename Compare,
    bool = IsEmpty<List>::value>
class InsertSortedT;

// recursive case 
template<
    typename List,
    typename Element,
    template<typename T, typename U> typename Compare>
class InsertSortedT<List, Element, Compare, false>
{
    using NewTail = typename IfThenElse<
        Compare<Element, Front<List>>::value,
        IdentityT<List>,
        InsertSortedT<PopFront<List>, Element, Compare>
        >::Type;

    using NewHead = IfThenElse<
          Compare<Element, Front<List>>::value,
          Element,
          Front<List>>;

    public:
        using Type = PushFront<NewTail, NewHead>;
};

// basis case:
template<
    typename List,
    typename Element,
    template<typename T, typename U> typename Compare>
class InsertSortedT<List, Element, Compare, true>
: public PushFrontT<List, Element>
{
};

template<
    typename List,
    typename Element,
    template<typename T, typename U> typename Compare>
using InsertSorted = typename InsertSortedT<List,Element,Compare>::Type;

#endif
