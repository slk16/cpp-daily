#pragma once

#ifndef DAY20260708H
#define DAY20260708H
#include <iostream>
namespace test {
// recommand : 
template<typename T, typename U>
inline auto add(const T& first,const U& second) -> decltype(first + second) {
    return (first + second);
}

template <typename T, typename U>
auto add_diff(T first, U second) {
    return first + second;
}

template <typename T>
auto add_same(T first, T second) {
    return first + second;
}

template <typename T>
auto add_same_test(T first, T second) {
    std::cout << "template add_2() called" << std::endl;
    return first + second;
}

} // namespace test


#endif // DAY20260708H