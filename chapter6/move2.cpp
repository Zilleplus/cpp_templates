#include<iostream>

class X{};
 
void g (X&){
    std::cout << "g() for variable \n";
}

void g (X const&){
    std::cout << "g() for constant \n";
}

void g(X&&){
    std::cout << "g() for movable object \n";
}

template<typename T>
void f(T&& val){
    g(std::forward<T>(val));
    //g(std::move(val)); // we can't use this, as otherwise the first call to v would move then it shouldn't
}

int main(){
    X v;
    X const c;

    f(v);
    f(c);
    f(X());
    f(std::move(v));
}
