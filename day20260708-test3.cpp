#include <iostream>
#include <memory>

int main() {
    // noexcept(表达式)为编译期常量
    std::cout << "noexcept(1 + 1) : " << noexcept(1 + 1) << std::endl;
    std::cout << "noexcept(std::cout << 1)" << noexcept(std::cout << 1) << std::endl;
    std::cout << "noexcept()" << noexcept(std::declval<std::unique_ptr<int>>() = std::declval<std::unique_ptr<int>>()) << std::endl;



    return 0;
}