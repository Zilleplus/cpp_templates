#include "duration.hpp"
#include "durationadd.hpp"

int main()
{
    int x = 42;
    int y = 77;

    auto a = Duration<int, Ratio<1,1000>>(x);
    auto b = Duration<int, Ratio<2,3>>(y);

    auto c = a + b;
}
