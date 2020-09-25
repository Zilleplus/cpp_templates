#ifndef TUPLETYPELIST_HPP
#define TUPLETYPELIST_HPP

#include"tuple0.hpp"

// i don't wanna mix all these templates from different chapters so gonna redefine the primary templates over here
template<typename T>
struct IsEmpty;

template<>
struct IsEmpty<Tuple<>>{
    static constexpr bool value = true;
};

template<typename T>
struct FrontT;

template<typename Head, typename... Tail>
struct FrontT<Tuple<Head, Tail...>>{
        using Type = Head;
};

template<typename T>
struct PopFrontT;

template<typename Head, typename... Tail>
struct PopFrontT<Tuple<Head, Tail...>>{
        using Type = Tuple<Tail...>;
};

template<typename T, typename U>
struct PushBackT;

template<typename... Types, typename Element>
struct PushBackT<Tuple<Types...>, Element>{
    using Type = Tuple<Types..., Element>;
};

#endif
