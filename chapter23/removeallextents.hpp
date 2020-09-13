#include<cstddef>

// primary template: in general we yield the given type
template<typename T>
struct RemoveAllExtendsT{
    using Type = T;
};

// partial specializations for array type(with and without bounds):
template<typename T, std::size_t SZ>
struct RemoveAllExtendsT<T[SZ]>{
    using Type = typename RemoveAllExtendsT<T>::Type;
};
template<typename T>
struct RemoveAllExtendsT<T[]>{
    using Type = typename RemoveAllExtendsT<T>::Type;
};

template<typename T>
using RemoveAllExtends = typename RemoveAllExtendsT<T>::Type;
