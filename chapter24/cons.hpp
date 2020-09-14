#ifndef CONST_HPP
#define CONST_HPP

class Nil{};

template<typename HeadT, typename TailT = Nil>
struct Cons{
    using Head = HeadT;
    using Tail = TailT;
};

#endif
