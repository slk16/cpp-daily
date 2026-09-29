#include <iostream>
#include <thread>
#include <random>

namespace test {
    void hello() {
        std::cout << "Hello Concurrent World";
    }
    struct func {
        int& i_;
        func(int& i) : i_(i) { }
        void operator()() {
            for (int i = 0; i < 10000; ++i) {
                this->i_ += 3; 
            }
            std::cout << i_ << std::endl;
        }
    };
    void random_throw() {
        std::random_device rd{};
        if (rd() % 2)
            throw std::runtime_error("random throw!");
    }
    void do_something() {
        random_throw();
    }
    void test01() {
        int some_local_state = 30;
        func f{some_local_state};
        std::thread t{ f };
        try {
            do_something();
        } catch (...){
            t.join();
            throw;
        }
        t.join();
    }
    void test02() {
        
    }
    void oops() {
        int some_local_state = 10;
        func f{some_local_state};
        std::thread t{f};
        t.detach();
    }
} // namespace test


int main() {
    std::cout << "begin" << std::endl;
    test::test01(); 

    return 0;
}