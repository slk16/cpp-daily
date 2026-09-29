#include <atomic>
#include <iostream>
#include <random>
#include <thread>

namespace test {
    void test01_join() {
        std::cout << " --- test01_join() --- " << std::endl;
        int a = 10;
        std::thread th{[&a]() {
            a *= a; 
        }}; 
        //std::thread th{[v = std::ref(a)]() {
        //    v *= v;
        //}};
        th.join();
        std::cout << a << std::endl;
    }
    void test01_detach() {
        std::cout << " --- test01_detach() --- " << std::endl;
        int a = 10;
        std::thread th{[&a]() {
            a *= a; 
        }};
        th.detach();
        //std::this_thread::sleep_for(std::chrono::microseconds(1000));
        //detach之后a的值并不确定
        //产生了一个悬垂引用
        std::cout << a << std::endl;
    }
    void test01() {
        test01_join();
        test01_detach();
    }
    class ThreadGuard {
    private:
        std::thread& th_;
    public:
        ThreadGuard(std::thread& th) : th_(th) {}
        ~ThreadGuard() {
            th_.join();
        }
    };
    void test02() {
        int a = 20;
        std::thread th{ [&a](std::size_t k = 10) {
            for (std::size_t i = 0; i < k; ++i) {
                a += i + 1;
            }
        }}; 
        std::cout << std::boolalpha << th.joinable() << std::endl;//true
        ThreadGuard {th};
        std::cout << std::boolalpha << th.joinable() << std::endl;//false
        std::cout << "result : " << a << std::endl;
    }
    void random_throw(int rate) { // [1, 100] rate to throw
        static std::default_random_engine eng{std::random_device{}()};
        static std::uniform_int_distribution dist{1, 100};
        if (dist(eng) <= rate) {
            throw std::runtime_error("random_throw for test");
        }
    } 
    void test03_throw() {
        int ret = 0;
        std::thread th{[&ret]() {
            for (int i = 1; i <= 100; ++i) {
                ret += i;
            }
        }};
        try { // 不加try catch使得random_throw跳过join直接析构thread对象
            random_throw(50);
        } catch (...) {
            th.join();
            std::cout << "random_throw : th.join()" << std::endl;
            throw;
        }
        th.join();
        std::cout << "ret : " << ret << std::endl;
    }
    void test03() {
        try {
            test03_throw();
        } catch(std::runtime_error re) {
            std::cout << "Exception : " << re.what() << std::endl;
        }
    }
    
    void test04() {
        //向线程传递参数
        std::thread th{ []() {
        }};
        std::cout << "th.get_id() : " << th.get_id() << std::endl;
        th.join();
    }
    void test05() {
        std::string s = "yeah. string";
        std::cout << s << std::endl;
        std::unique_ptr<std::string> sptr = std::make_unique<std::string>(s);        
        //std::unique_ptr<std::string> sptr2(&s); // double free
        std::cout << *sptr << std::endl;
        s = "no. string";
        std::cout << *sptr << std::endl;
        // make_unique创建的是独有的资源
    }
    void test06() {
        int a = 10;
        std::thread th{[](const int& a) {
            std::cout << &a << std::endl;
        }, a};
        std::cout << &a << std::endl;
        th.join();
    }
    void test07() {
        
    }
} // namespace test

int main() {
    test::test06(); 



    return 0;
}