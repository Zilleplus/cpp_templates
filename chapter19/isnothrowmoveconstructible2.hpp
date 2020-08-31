#include <utility> // declval
#include <type_traits> // true_type/ false_type/ bool_constant<>

// primary template
template<typename T, typename = std::void_t<>>
struct IsNothrowMoveConstructibleT : std::false_type
{
};

// partial specializatin
template<typename T>
struct IsNothrowMoveConstructibleT<T, std::void_t<decltype(T(std::declval<T>()))>>
    : std::bool_constant<noexcept(T(std::declval<T>()))>
{
};

