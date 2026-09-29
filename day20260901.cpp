#include <iostream>
#include <functional>

namespace test {
    void print(int&& a) {
        std::cout << a << std::endl;
    }
    void test01() {
        int a = 20;         
        //auto au_print = std::bind(print, 20); // std::bind左值传递参数副本
        //au_print();
        auto au_print = []() { print(20); };
        au_print();
    }
    void test02() {
        
    }
} // namespace test

int main() {
    test::test01();

    return 0;
}