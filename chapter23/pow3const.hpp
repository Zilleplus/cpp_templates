// primary template to compute 3 to the Nth
template<int N>
struct Pow3{
    static int const value = 3* Pow3<N-1>::value;
};

// full specialization to end the recusion
template<>
struct Pow3<0>{
    static int const value = 1;
};

// note:
// foo(Pow<7>::value); 
// with: void foo(int const&);
// -> need to allocate memory to save Pow<7>'s result as 
// we need the address.
