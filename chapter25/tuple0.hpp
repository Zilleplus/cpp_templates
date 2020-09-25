#ifndef TULPE0_HPP 
#define TULPE0_HPP

#include<utility>

template<typename... Types>
class Tuple;

// recursive case:
template<typename Head, typename... Tail>
class Tuple<Head, Tail...>
{
    private:
        Head head;
        Tuple<Tail...> tail;

    public:
        Tuple(){}

        // ctor is different from book seem to work here
        // not sure why they use seperate template list in 
        // the book.
        Tuple(Head&& head,  Tuple<Tail...>&& tail) :
            head(std::forward<Head>(head)),
            tail(std::forward<Tail...>(tail))
        {} 
        Tuple(Head&& head,  Tail&&... tail) :
            head(std::forward<Head>(head)),
            tail(std::forward<Tail>(tail)...)
        {}

        Head& getHead(){return head;}
        Head const& getHead() const {return head;}

        Tuple<Tail...>& getTail() { return tail;}
        Tuple<Tail...> const& getTail() const { return tail;}
};

template<>
class Tuple<>{
    // no storage required
};

#endif
