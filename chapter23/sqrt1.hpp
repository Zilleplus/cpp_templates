// primary template to compute sqrt(n)
template<int N, int LO=1, int HI=N>
struct Sqrt{
    // compure the midpoint, rounded up
    static constexpr auto mid = (LO+HI)/2;

    // search a not too large value in a halved interval
    // The negative side of this approach is that both Sqrt
    // objects here are made inside the compile process,
    // this slows down the compilation process.
    static constexpr auto value = (N< mid*mid) 
        ? Sqrt<N,LO,mid-1>::value 
        : Sqrt<N,mid,HI>::value;
};
