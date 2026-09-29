#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <thread>
#include <mutex>

namespace test {
    namespace t1{
        void test01() {
            std::vector<int> v; 
            std::random_device rd;
            for (int i = 0; i < 10; ++i) {
                v.push_back(rd() % 1000); 
            }
            std::partial_sort(v.begin(), v.begin() + 3, v.end());                  
            for (auto trans : v) {
                std::cout << trans << " ";
            }
        }
    } // 
    namespace t2 {
        std::mutex mtx;
        void print(const std::string& str) {
            for (int i = 0; i < 10; ++i) {
                {
                    std::lock_guard<std::mutex> lk(mtx);
                    std::cout << "print " << i + 1 << ": " << str << std::endl;
                }
                std::this_thread::yield();
            }
        }
        void test01() {
            std::thread pr1(print, "t1 hello world"); 
            std::thread pr2(print, "t2 world hello");
            pr2.detach();
            pr1.join();
            return ;
        }

    } // 并发的学习


} // namespace test

int main() {
    test::t2::test01();


    std::cout << "finish" << std::endl;
    return 0;
}