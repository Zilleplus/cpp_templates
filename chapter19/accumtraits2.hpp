template<typename T>
struct AccumulationTraits;

template<>
struct AccumulationTraits<char>{
    using Acct = int;
};

template<>
struct AccumulationTraits<short>{
    using Acct = int;
};

template<>
struct AccumulationTraits<int>{
    using Acct = long;
};

template<>
struct AccumulationTraits<unsigned int>{
    using Acct = unsigned long;
};

template<>
struct AccumulationTraits<float>{
    using Acct = double;
};
