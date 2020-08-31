template<typename T>
struct AccumulationTraits;

template<>
struct AccumulationTraits<char>{
    using Acct = int;
    static Acct const zero = 0;
};

template<>
struct AccumulationTraits<short>{
    using Acct = int;
    static Acct const zero = 0;
};

template<>
struct AccumulationTraits<int>{
    using Acct = long;
    static Acct const zero = 0;
};

template<>
struct AccumulationTraits<unsigned int>{
    using Acct = unsigned long;
    static Acct const zero = 0;
};

template<>
struct AccumulationTraits<float>{
    using Acct = double;
    // Constexpr is only required if not integral or enum value.
    static constexpr Acct const zero = 0; 
    //static Acct const zero = 0; 
    inline static Acct const zero2 = 0;  // inline stuff does work
};
