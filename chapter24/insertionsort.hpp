#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include"typelistisempty.hpp"
#include"typelistfront.hpp"
#include"typelistpopfront.hpp"
#include"insertSorted.hpp"

template<typename List,
    template<typename T, typename U> typename Compare,
    bool = IsEmpty<List>::value>
struct InsertionSortT;

template<typename List,
    template<typename T, typename U> typename Compare>
using InsertionSort = typename InsertionSortT<List, Compare>::Type;

// recursive case (insert first element into sorted list)
template<typename List,
    template<typename T, typename U> typename Compare >
struct InsertionSortT<List, Compare, false>
: public InsertSortedT<
    InsertionSort<PopFront<List>, Compare>,
    Front<List>,
    Compare>
{
};

// basic case (an empty list is sorted)
template<typename List,
    template< typename T, typename U> typename Compare>
struct InsertionSortT<List, Compare, true>
{
    using Type = List;
};

#endif
