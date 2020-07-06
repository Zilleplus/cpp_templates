#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

template <typename T>
using EnableIfString = std::enable_if_t<std::is_convertible<T, std::string>::value>;

class Person {
private:
    std::string name;

public:
    template <typename STR, typename = EnableIfString<STR>>
    explicit Person(STR&& n)
        : name(std::forward<STR>(n))
    {
        std::cout << "TMPL-CONSTR for `" << name << "`\n";
    }

    // copy and move constructor:
    Person(Person const& p)
        : name(p.name)
    {
        std::cout << "COPY-CONSTR Person'" << name << "'\n";
    }

    Person(Person&& p)
        : name(std::move(p.name))
    {
        std::cout << "MOVE-CONSTR Person'" << name << "'\n";
    }
};

int main()
{
    std::string s = "sname";
    // These two call the string constructor that is templated:
    Person p1(s);     
    Person p2("tmp");
    // Normal copy/move ctor:
    Person p3(p1); // call's the copy ctor.
    Person p4(std::move(p1)); // call's move
}
