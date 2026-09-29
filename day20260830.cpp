#include <iostream>
#include <thread>

//#define container_of(ptr,type,member) ({\
//    const typeof(((type*)0)->member) *__mptr = ptr;\
//    (type*)((char*)__mptr - offsetof(type, member));\
//}) //可以看出c and cpp的相通性，同样的编译期计算

namespace test {
    template <typename T>
    void func(const T& a) {
        std::cout << *a << std::endl;
    } 
    void test01() {
        std::unique_ptr<int> uptri = std::make_unique<int>(20);
        std::thread th{func<decltype(uptri)>, std::move(uptri)};    
        th.join();
    }
    void test02() {
    }
    void test03() {
        int a = 10;
        typedef int integer;
        integer& b = a;
        decltype(b) c = b;
    }
} // namespace test

int main() {
    //test::test01();
    test::test02();

    //std::cout << "finish" << std::endl;
    //std::terminate();
    return 0;
}