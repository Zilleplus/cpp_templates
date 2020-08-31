template<typename T>
struct RemoveConstT{
    using Type = T;
};

template<typename T>
struct RemoveConstT<const T>{
    using Type = T;
};

template<typename T>
using RemoveConst = typename RemoveConstT<T>::Type;
