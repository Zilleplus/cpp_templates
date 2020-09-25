#ifndef TUPLEGET_HPP
#define TUPLEGET_HPP

#include"tuple0.hpp"

template<unsigned N>
struct TupleGet{
    template<typename Head, typename... Tail>
    static auto Apply(Tuple<Head, Tail...> const& t){
        return TupleGet<N-1>::Apply(t.getTail());
    }
};

template<>
struct TupleGet<0>{
    template<typename Head, typename... Tail>
    static auto Apply(Tuple<Head, Tail...> const& t){
        return t.getHead();
    }
};

template<unsigned N, typename... Types>
auto get(Tuple<Types...> const& t){
    return TupleGet<N>::Apply(t);
}

#endif
