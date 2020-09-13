#include"ifthenelse.hpp"

// primary template for the main recusive step
template<int N, int LO=1, int HI=N>
struct Sqrt{
    // compute the midpoint, rounded up
    static constexpr auto mid = (LO+HI)/2;

    // search a not too large value in the halved interval
    using SubT = IfThenElse<
          (N<mid*mid),
          Sqrt<N,LO,mid-1>,
          Sqrt<N,mid,HI>>;

    static constexpr auto value = SubT::value;
};

// partial special for end of recusion criterion
template<int N, int S>
struct Sqrt<N,S,S>{
    static constexpr auto value = 5;
};
