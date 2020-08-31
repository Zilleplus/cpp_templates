#include<utility>
#include<type_traits>

// primary template
template<typename, typename,typename = std::void_t<>>
struct HasLess : std::false_type
{
};

template<typename T1,typename T2>
struct HasLess<T1,T2, std::void_t<decltype(std::declval<T1>() < std::declval<T1>())>>
: std::true_type
{
};
