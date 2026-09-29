#include <iostream>
#include <thread>
#include <type_traits>

namespace test {
    class foo {
    public:
        operator int() {
            return 5;
        }
        operator const char*() {
            return "hello world";
        }
    };
    void f(const int& a) {
        std::cout << "f : " << &a << std::endl;
    }
    void test01() {
        int a = 20;
        std::thread th{f, a}; 
        std::cout << "test01 : " << &a<< std::endl;
        th.join();
    }
    void test02() {
        std::integral_constant<bool, true> a;
    }
    namespace learn_id {
        class foo {
            void func(int a = 10);
            int f = 20;
        };
        void foo::func(int a) {
            std::cout << f << std::endl; 
        }
        namespace ran{
            namespace bar3 {
                int i = 20;
            }
        }
        namespace bar {
            using ran::bar3::i;
            extern int j;     
        }
        namespace bar2 {
           extern int f; 
           int f = 20;
           void test02() {
               std::cout << f << std::endl;
           }
        }
        int i = 10;
        int bar::j = i;
        void test01() {
            //std::cout << j << std::endl; // 找不到，声明与定义相分离
            std::cout << bar::j << std::endl;
        }
    }
    namespace learn_id2 {
        namespace bar {
            void func_f(int i = 20) {
                std::cout << "i : " << i << std::endl;
            }
        }
        void test01() {
            using bar::func_f;

        }
        void func_f(char a = 'a');
        void test02() {
            using namespace bar;
            //func_f(); // 重载失败
        }
    }
}

int main() {
    test::learn_id::test01();
    
    return 0;
}