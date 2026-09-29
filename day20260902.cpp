#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <algorithm>

namespace test {
    template <typename T1, typename T2>
    auto max(T1 a, T2 b) -> decltype(b < a ? a : b) {

    }
    void test01() {
        int a = 20;
        int& refa = a;
        decltype(refa) decl1= a;
        int&& b = 3;
        decltype(b) decl2= 3;
    }
    //template <typename... Args1, typename... Args2>
    //decltype(auto) pef_add(Args1&&... args1, Args2&&... args2) {
    //    auto ret = (args1 + args2)...;
    //}
    decltype(auto) f1() {
        static int x;
        return x;
    }
    auto f2() {
        static int x;
        return (x);
    }
    void test02() {
        //decltype(std::declval<int>() + std::declval<unsigned>()) a = 20;

    }
    void test03() {
        int i = 20;
        i = ++i;
        std::cout << i << std::endl;
    }
    struct A {
        A(int i) { std::cout << i; }

    };
    struct any {
        any(...) {};
    };
    void test04() {
        any( A(0), A(1)); 
        std::cout << std::endl;
        any{ A(0), A(1)};
        std::cout << std::endl;
    }
    void test05() {
        struct three_int {
            int a;
            int b;
            int c;
            void print() {
                std::cout << "a : " << a << '\n'
                << "b : " << b << '\n'
                << "c : " << c << std::endl;
            }
        } ti;
        auto pb = &three_int::b;
        auto i = ti.*pb; // 好诡异
    }

    void test06() {
        std::atomic<bool> ready = false;
        //std::atomic<std::string> astr = "hello"; // isn't trivially copyable
        int data = 0;
        std::thread producer([&] {
            data = 42;
            ready.store(true, std::memory_order::memory_order_relaxed);
        });
        std::thread consumer([&] {
            if (ready.load(std::memory_order::memory_order_relaxed)) //x86平台强内存模型导致没法观察到错误
                std::cout << data;
        });
        producer.join();
        consumer.join();
    }
    void test07() {
        char arr[1024];
        char ch;
        std::decay<decltype(arr)>::type pch = &ch;
        auto ptarr= static_cast<char*> (arr);
    }
    void test08() {
        //class foo {
        //    template <typename T>
        //    void operator()(T a) {
        //        std::cout << a << std::endl; 
        //    }
        //};
        std::vector<int> a{1,2,3};
        std::vector<int> v = std::move_if_noexcept<std::vector<int>>(a);
        auto print = [](auto a){
            std::for_each(a.begin(), a.end(), [](int i) {
                    std::cout << i << ' ';
                    });
        };
    }
    namespace test_name {
        
    }
} // namespace test

int main() {
    test::test08();

    return 0;
}