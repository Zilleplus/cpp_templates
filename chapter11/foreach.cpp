#include<iostream>
#include<vector>
#include"foreach.hpp"

// a function to call
void func(int i)
{
    std::cout << "func() called for : " << i << '\n';
}

class FuncObj{
    public:
        void operator() (int i) const{ // note const
            std::cout << "Func::op() called for " << i << '\n';
        }
};

int main()
{
    std::vector<int> primes = {2,3,5,7,11,13, 17,19};

    foreach(primes.begin(),primes.end(), func);

    foreach(primes.begin(),primes.end(), &func);

    foreach(primes.begin(),primes.end(), FuncObj());

    foreach(primes.begin(),primes.end(), 
            [](int i){
                std::cout << "lambda called for: " << i << '\n';
            });
}
