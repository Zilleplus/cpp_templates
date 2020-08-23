class Collection{
    public:
        template<typename T>
        class Node{
        };

        template<typename T> // inclass and (so implicitly inline)
        T* alloc(){          // member function template definition
        };

        template<typename T> // a member variable template(since c++14)
        static T zero = 0;

        template<typename T> // member alias template
        using NodePrt = Node<T>*;
};
