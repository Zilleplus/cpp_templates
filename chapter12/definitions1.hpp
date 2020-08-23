template<typename Y>
class Data{
    public:
        static constexpr bool copyable = true;
};

template<typename T>
void Log(T x){
}

template<typename T> // a namespace scope variable template (since C++14)
T zero = 0;

template<typename T> // an namespace scope variable template (since c++14)
bool dataCopyable = Data<T>::copyable;

template<typename T>
using DataList = Data<T*>;
