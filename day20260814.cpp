#include <iostream>
#include <thread>


namespace test {
    class Task{
    public:
        void operator()() {
            std::cout << "hello world" << std::endl;
        }
    };
    void test01() {
        //std::thread t(Task()); // disambiguated as a function
        //void h(int(*p)(int));
        //void h(int(int));
        std::thread t(Task{});
        t.join();
    }

    namespace test_namespace {
        namespace lib2 {
            template <typename T>
            void print([[maybe_unused]]T s) {
                std::cout << "print() from ::test::test_namespace::lib2" << std::endl;
            }
        }
        namespace lib {
            using namespace lib2;
            struct st {
                
            };
            void print([[maybe_unused]]st s) {
                std::cout << "print() from ::test::test_namespace::lib" << std::endl;                
            }
        }
        void print([[maybe_unused]]lib::st s) {
            std::cout << "print() from ::test::test_namespace" << std::endl; 
        }
        void test01() {
            lib::st s; 
            //print(s); // ambiguous
            (print)(s); // ADL不会去using-directives中来查找，加括号避免adl
        }
    }
    namespace test_namespace2 {

    }
} // namespace test

int main() {
    //test::test01();
    test::test_namespace::test01();
    int a{3};


    return 0;
}