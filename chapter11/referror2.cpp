#include<vector>
#include<iostream>
 
template<typename T, int& SZ> // note reference template parameter
class Arr{
    private:
        std::vector<T> elems;
    public:
        Arr(): elems(SZ){}

        void print() const {
            for (int i = 0;i<SZ;++i){
                std::cout << elems[i] << ' ';
            }
            std::cout << std::endl;
        }
};

static int size = 10;

int main()
{
    // Arr<int&,size> y; // compile-time Error deep in the code of class std::vector<>

    Arr<int, size> x; // init internal vector with 10 elements
    x.print(); // OK 
    size +=100;
    x.print(); // prints 100 elements lol... gebrish...
}
