#include<utility> // declval

// helper: checking validity of f(args..) for F f and Args... args
template<
    typename F,
    typename... Args,
    typename = decltype(std::declval<F>()(std::declval<Args&&>()...))
    >
std::true_type isValidImp(void*);

// fallback if helper SFINAE out:
template<typename F, typename... Args>
std::false_type isValidImp(...);

// define a lambda that takes a lambda f and returns whether calling f with args is valid:
inline constexpr
auto isValid = [](auto f) {
    return [](auto&&... Args){
        return decltype(isValidImp<decltype(f),decltype(Args)&&...>(nullptr)){};
    };
};

// helper template to represent a type as a value:
template<typename T>
struct TypeT{
    using Type = T;
};

// helper to wrap a type as a value
template<typename T>
constexpr auto type = TypeT<T>{};

// helper to unwarp a wrapped type in unevaluated contexts
template<typename T>
T valueT(TypeT<T>); // no definition needed

constexpr auto isDefaultConstructible
    = isValid([](auto x) -> decltype((void) decltype(valueT(x))()){});
