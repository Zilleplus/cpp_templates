#ifndef CONSPOPFRONT_HPP
#define CONSPOPFRONT_HPP

template<typename List>
struct PopFrontT
{
    using Type = typename List::Tail;
};

template<typename List>
using PopFront = PopFrontT<List>;

#endif
