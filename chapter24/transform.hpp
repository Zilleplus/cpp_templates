#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include"typelistisempty.hpp"
#include"typelist.hpp"
#include"typelistpopfront.hpp"
#include"typelistpushfront.hpp"
#include"typelistfront.hpp"

template<
    typename List,
    template<typename T> typename MetaFun,
    bool Empty =  IsEmpty<List>::value>
struct TransformT;

// recursive case:
template<typename List, template<typename T> typename MetaFun>
struct TransformT<List, MetaFun, false>
: public PushFront<
    typename TransformT<PopFront<List>, MetaFun>::Type,
    typename MetaFun<Front<List>>::Type>
{
};


template<typename List, template<typename T> typename MetaFun>
struct TransformT<List, MetaFun, true>
{
    using Type = List;
};

template<typename List, template<typename T> typename MetaFun>
using Transform = typename TransformT<List,MetaFun>::Type;


#endif
