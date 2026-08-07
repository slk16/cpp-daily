#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unistd.h>
namespace test {
    void test01() {
        // Floating point exception (core dumped)
        int b = 0;
        std::cout << b << std::endl;
        int a = 2 / b;
        std::cout << a << std::endl;
    }
    
    void test02() {
        // Segmentation fault (core dumped)
        int* p = (int*)0x2244668812345678;
        std::cout << *p << std::endl;
    }

}

int main() {
    test::test02();


    return 0;
}