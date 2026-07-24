#include <iostream>

#include "day20260708.hpp"
//模版是在编译期生成的代码，需要包含在头文件中

namespace test {
double add_same_test(double a, double b) {
    std::cout << "normal add_2 called" << std::endl;
    return a + b;
}
void test01() {
    std::cout << "test01 begin : " << std::endl;
    std::cout << "--------------------------------" << std::endl;

double ret1 = add_diff(1,2.0);
    std::cout << "ret1 : " << ret1 << std::endl; // 模版允许加法使用不同操作数，内部采用隐式类型转换

    std::cout << "--------------------------------" << std::endl;

    // auto ret2 = test::add_1(1,2); // OK
    // auto ret2 = test::add_1(1, 2.0); // error 模版不允许隐式类型转换
auto ret2 = add_same<int>(1,2.0); // ok 模版允许显式类型转换
    std::cout << "ret2 : " << ret2 << std::endl;

    std::cout << "--------------------------------" << std::endl;

auto ret3 = add_same_test(1.0,4.0); // 普通函数优先
    std::cout << "ret3 : " << ret3 << std::endl;
}

} // namespace test

int main() {
    


    return 0;
}