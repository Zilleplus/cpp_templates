#include"isvalid.hpp"
#include<iostream>
#include<string>
#include<utility>

int main()
{
    using namespace std;
    cout << boolalpha;

    // define to check for data member first
    constexpr auto hasFirst
        = isValid([](auto x) -> decltype((void) valueT(x).first){
                });

    cout << "hasFirst: " << hasFirst(type<pair<int,int>>) << '\n'; // true

    constexpr auto hasSizeType
        = isValid([](auto x) -> typename decltype(valueT(x))::size_type{
                });

    struct CX{
        using size_type = std::size_t;
    };
    cout << "hasSizeType: " << hasSizeType(type<CX>) << '\n'; // true

    if  constexpr(!hasSizeType(type<int>)){
        cout << "int has no in size type\n";
    }

    // define to check for:
    constexpr auto hasLess
        = isValid([](auto x, auto y) -> decltype(valueT(x) < valueT(y)){});
    constexpr auto hasLess2
        = isValid([](auto x, auto y) -> decltype(x < valueT(y)){});

    cout << hasLess(42, type<char>) << '\n'; // yields true according to the book, however
    // this makes to sense to me, 42 is not of type value<T>, and so the hasless will 
    // be sfinae'd out. The hasLess 2 function will work in this case.
    cout << hasLess(type<std::string>, type<std::string>) << '\n'; // yields true
    cout << hasLess(type<std::string>, type<int>) << '\n'; // yields false
    cout << hasLess(type<std::string>, "hello") << '\n'; // yields true
}
