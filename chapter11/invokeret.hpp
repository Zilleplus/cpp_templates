#include<utility> // std::invoke
#include<functional> // std::invoke
#include<type_traits>

template<typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args)
{
    if constexpr(std::is_same_v<std::invoke_result_t<Callable, Args...>,void>){
        std::invoke(
                std::forward<Callable>(op),
                std::forward<Args>(args)...);
        return;
    }
    else {
        decltype(auto) ret{std::invoke(
                std::forward<Callable>(op),
                std::forward<Args>(args)...)};

        return ret;
    }
}

