#include<utility>
#include<type_traits>

// primary template
template<typename, typename = std::void_t<>>
struct HasBeginT : std::false_type{
};

template<typename T>
struct HasBeginT<T, std::void_t<decltype(std::declval<T>().begin())>>
: std::true_type{
};
