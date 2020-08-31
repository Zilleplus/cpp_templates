#include<type_traits>

template<typename T>
struct IsDefaultConstructableHelper{
    private:
        template<typename U, typename = decltype(U())>
            static std::true_type test(void*);

        template<typename U>
            static std::false_type test(...);

    public:
        using Type = decltype(test<T>(nullptr));
};

template<typename T>
struct ISDefaultConstructibleT : IsDefaultConstructableHelper<T>::Type{
};
