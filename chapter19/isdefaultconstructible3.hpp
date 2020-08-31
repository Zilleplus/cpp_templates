#include"issame.hpp"
#include<type_traits>

template<typename...>
using VoidT = void;

template<typename, typename = VoidT<>>
struct IsDefaultConstructableT : std::false_type
{
};

template<typename T>
struct IsDefaultConstructableT<T, VoidT<decltype(T())>> : std::true_type
{
};
