#include <type_traits> // for true_type and false_type
#include <utility>  // for declval

template<typename FROM,typename TO>
struct IsConvertibleHelper{
    private:
        // test() trying to call the help aux(to) for a FROM pass as F:
        static void aux(TO);
        // F and T tempalte parameter are required here to keep the whole
        // thing inside the SFINEA context.
        template<
            typename F,
            typename T, 
            typename = decltype(aux(std::declval<F>()))>
        static std::true_type test(void*);

        // test() fallback:
        template<typename, typename>
        static std::false_type test(...);
    public:
        using Type = decltype(test<FROM>(nullptr));
};

template<typename FROM, typename TO>
struct IsConvertibleT : IsConvertibleHelper<FROM,TO>::Type{
};

template<typename FROM, typename TO>
using IsConvertible = typename IsConvertibleT<FROM,TO>::Type;

template<typename FROM, typename TO>
constexpr bool IsConvertible_v = IsConvertibleT<FROM,TO>::value;
