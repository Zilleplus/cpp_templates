// primary template to compure 3 to the Nth
template<int N>
struct Pow3{
    enum{value =3* Pow3<N-1>::value};
};

template<>
struct Pow3<0>{
    enum{value = 1};
};
