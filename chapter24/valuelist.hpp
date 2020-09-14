#ifndef VALUELIST_HPP
#define VALUELIST_HPP

#include"typelistisempty.hpp"
#include"typelistfront.hpp"
#include"typelistpopfront.hpp"
#include"typelistpushfront.hpp"
#include"typelistpushback.hpp"
#include "ctvalue.hpp"

template<typename T, T... Values>
struct Valuelist{
};

template<typename T, T... Values>
struct IsEmpty<Valuelist<T, Values...>>{
    static constexpr bool value = sizeof...(Values) == 0;
};

template<typename T, T Head, T... Tail>
struct FrontT<Valuelist<T, Head, Tail...>>{
    using Type = CTValue<T, Head>;
    static constexpr T Value = Head;
};

template<typename T, T Head, T... Tail>
struct PopFrontT<Valuelist<T, Head, Tail...>>{
    using Type = Valuelist<T, Tail...>;
};

template<typename T, T... Values, T New>
struct PushFrontT<Valuelist<T, Values...>, CTValue<T, New>>{
    using Type = Valuelist<T, New , Values... >;
};

template<typename T, T... Values, T New>
struct PushBackT<Valuelist<T, Values...>, CTValue<T, New>>{
    using type = Valuelist<T, Values..., New>;
};

#endif
