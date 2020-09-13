#ifndef RATIO_H
#define RATIO_H

template<unsigned N, unsigned D = 1>
struct Ratio{
    static constexpr unsigned num = N;
    static constexpr unsigned den = D;
    using Type = Ratio<num,den>;
};

#endif
