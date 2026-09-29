#include <iostream>
#include <random>

namespace test {
    int div16(int x) {
        unsigned int v = (((unsigned)x) >> 31);
        v |= (v << 1);
        v |= (v << 2);
        return (signed int)(x + v) >> 4;
    }
    void test01() {
        std::random_device rd; 
        bool ret = true;
        int temp;
        for (int i = 10000; i; --i) {
            temp = rd();
            if (temp / 16 != div16(temp)) {
                ret = false;
            }
        }
        std::cout << std::boolalpha << ret << std::endl;
    }
} // namespace test


int main() {
    test::test01();


    return 0;
}