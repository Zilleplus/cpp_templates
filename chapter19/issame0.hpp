template<typename T1, typename T2>
struct IsSameT{
    static constexpr bool value = false;
};

template<typename T>
struct IsSameT<T, T>{
    static constexpr bool value = true;
};

template<typename T1, typename T2>
constexpr bool isSame = IsSameT<T1,T2>::value;
