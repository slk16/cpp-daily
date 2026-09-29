#include <iostream>
#include <thread>
namespace test {
    void test01() {
        std::thread t{[](int a = 0) {
            int sum = 0;
            for (int i = a; i <= a + 100; ++i) {
               sum += i; 
            }
            std::cout << "sum : " << sum << std::endl;
        }, 10};
        t.detach();
    }
}

int main() {
    test::test01();

    return 0;
}