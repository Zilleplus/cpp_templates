// Mentioned in the text on page 205.
#include<iostream>

void print()
{
    std::cout << std::endl;
}
template<typename Type ,typename... Types>
void print(Type arg, Types... args)
{
    std::cout << arg;
    print(args...);
}

// c++17 fold expressions are awwwwsome
template<typename... Types>
void print_fold_expr(Types... args)
{
    (std::cout << ... << args) << std::endl;
}

int main()
{
    print("start demo");
    print("aa","bb");
    print_fold_expr("cc","dd");
    print_fold_expr(); // This works !
    print("end demo");
}
