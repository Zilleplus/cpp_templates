#ifndef VARIADICTRANSFORM_HPP
#define VARIADICTRANSFORM_HPP

#include"typelist.hpp"
#include"transform.hpp"

template<typename... Elements, template<typename T> typename MetaFun>
struct TransformT<Typelist<Elements...>, MetaFun, false>
{
    using Type = Typelist<typename MetaFun<Elements>::Type...>;
};

#endif
