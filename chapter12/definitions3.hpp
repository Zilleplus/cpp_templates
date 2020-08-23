template<typename T>
class List{
    public:
        List() = default; // because a template ctor is defined

        template<typename U>
        class Handle;

        template<typename U>
        List (List<U> const&);

        template<typename U>
        static U zero;
};


template<typename T> // class template T
    template<typename U>
class List<T>::Handle{
};

template<typename T> // class template T
    template<typename T2>
List<T>::List(List<T2> const& b){
};

template<typename T> // class template
    template<typename U>
U List<T>::zero=0;
