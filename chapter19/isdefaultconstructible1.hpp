#include "issame.hpp"

template<typename T>
struct IsDefaultConstructibleT{
    private:
        // Test() trying substitute call of a default constructor for T passed as U
        template<typename U, typename = decltype(U())>
            static char test (void*);

        // test() fallback:
        template<typename>
            static long test(...);
    public:
        static constexpr bool value
            = IsSameT<decltype(test<T>(nullprt)), char>::value;
};
