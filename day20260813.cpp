#include <iostream>
#include <vector>
#include <iterator>

namespace test_cout{
    void print() {
        std::cout << "output from namespace ::test::test_cout" << std::endl;
    }
}
namespace test {
    namespace test_cout{
        void print() {
            std::cout << "output from namespace ::test::test_cout" << std::endl;
        } 
    }
    void test01() {
        std::vector<int> ivec{ 1,2,3,4,5 };
        auto back = std::back_inserter(ivec);
        auto print = [&ivec](){
            std::cout << "print : ";
            for (auto trans : ivec) {
                std::cout << trans << ' ';
            }
            std::cout << std::endl;
        };
        [[maybe_unused]] auto front = std::front_inserter(ivec);
        print();
        for (int i = 10; i >=6; --i) {
            *back = i;
        }
        print();
    }
    void test02() {
        test_cout::print();        
        //test_cout 为非限定名称查找(unqualified-name lookup)
    }    

    namespace test_namespace {
        namespace x {
            int x = 5;
        }
        namespace a {
            using namespace x;
            void h() {
                std::cout << "h() from a" << std::endl;
            } 
        }
        namespace b {
            using namespace x;
            void h() {
                std::cout << "h() from b" << std::endl;
            }
        }
        namespace ab{
            using namespace a;
            using namespace b;
            void h() {
                std::cout << "h() from ab" << std::endl;
            }
        }
        void test01() {
            std::cout << "test01() from ::test::test_namespace" << std::endl;
            ab::h();
            std::cout << "x : " << ab::x << std::endl;
        }
        //void test04() {
        //    std::cout << "test04() from ::test::test_namespace" << std::endl;
        //}
    } //namespace test_namespace
    using namespace test_namespace; 
    void test_ns() {
        ::test::test_namespace::test01();
    }
    void test03() {
        test_namespace::test01(); // test01() from ::test::test_namespace
        // 证明test_namespace进行了限定名称查找
    }
}// namespace test
namespace test_namespace {

    void test01() {
        std::cout << "test01() from ::test_namespace" << std::endl;
    }
    class foo {
    void operator()() {
        std::cout << "class foo() from ::test_namespace" << std::endl;
    }        
    };
    void foo() {
    std::cout << "function foo() from ::test_namespace" << std::endl;
    }
    void test02() {
    int foo = 5;
    }
    }
    void f() {
        std::cout << "f() from ::" << std::endl;
    }

int main() {
    //test::test02();
    //test::test03();
    test::test_ns();
    //f();


    return 0;
}

void f(int = 5) {
    std::cout << "f(int = 5) from ::" << std::endl;
}