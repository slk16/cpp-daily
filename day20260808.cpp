#include <iostream>
#include <memory>

namespace test {

    class B;
    class A {
    public:
        B* ptr;
        std::unique_ptr<B> uptr;
    public:
        void print();
        //void print() {
        //    ptr->print();
        //} // 创建变量，调用成员函数需要声明
    };
    class B {
        void print() {
            std::cout << "hello from class B" << std::endl;
        }
    };
    void A::print() {

    }
    void test01() {


    }

} // namespace test


int main() {
    test::test01();


    return 0;
}