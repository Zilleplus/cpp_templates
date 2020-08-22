#include<iostream>

template<typename T>
void templPramIsReference(T){
    std::cout << "T is reference: " << std::is_reference_v<T> << '\n';
}

int main()
{
    std::cout << std::boolalpha;
    int i;
    int& r = i;
    templPramIsReference(i);
    templPramIsReference(r);
    templPramIsReference<int&>(i);
    templPramIsReference<int&>(i);
}
