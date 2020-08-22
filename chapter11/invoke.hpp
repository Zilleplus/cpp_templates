#include<utility> // std::invoke
#include<functional> // std::forward

// decltype(auto) == placeholder type (C++14 feature)
// => determines types form the type of the ossociated expression
// from page 301:
//
// int i = 42 -> has type iint
// int const& ref = i -> ref has type const&
// auto x = ref -> auto decay's so x has type int
// decltype(auto) y = ref -> y has type const& 
//
// !! void is an incomplete type type and 
// will cause trouble here with decltype(auto)
// 
// !! auto&& is not the correct return type,
// as it extend the lifetime of the returned value 
// until the end of of its scope.
template<typename Callable, typename... Args>
decltype(auto) call(
        Callable&& op,
        Args&&... args)
{
    return std::invoke(
        std::forward<Callable>(op),
        std::forward<Args>(args)...);
}
            
    
