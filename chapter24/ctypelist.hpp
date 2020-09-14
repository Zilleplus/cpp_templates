#ifndef CTYPELIST_HPP
#define CTYPELIST_HPP

#include"ctvalue.hpp"
#include"typelist.hpp"

template<typename T, T... Values>
using CTTypelist = Typelist<CTValue<T, Values>...>;

#endif
