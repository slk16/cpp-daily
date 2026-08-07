#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>
#include <string>

namespace test {
    namespace v1 {
        void test01() {
            std::vector<int> iv;
            iv.resize(20);
            std::iota(iv.begin(), iv.begin() + 20, 1);
            auto print = [](const std::vector<int>& iv) {
                std::cout << "heap : ";
                for (auto& trans : iv) {
                    std::cout << trans << " ";
                }
                std::cout << '\n';
            };
            print(iv);
            std::make_heap(iv.begin(), iv.end());
            print(iv);
            iv.push_back(30);
            std::push_heap(iv.begin(), iv.end());
            print(iv);
            std::pop_heap(iv.begin(), iv.end());
            print(iv);
        }

    }
    namespace v2 {
        template <typename T, typename R> inline
        T& min(T& a, T& b, R r = std::less<T>()) {
            return r(a, b) ? a : b;
        }
        //template <typename T> inline
        //T const& min(T const& a, T const& b) {
        //    return a < b ? a : b;
        //}
        template <typename T> inline
        T& max(T& a, T& b) {
            std::cout << "not std" << std::endl;
            return a < b ? a : b;
        }
        class foo{
        private:
        };
        void test02() {
            std::string a = "hello"; 
            std::string b = "world";
            
            auto ret = max(a,b);
            
            //int const a = 10;
            //int b = 20;
            //auto ret = min(a,b); // 显然 没有const类别时 会导致non-const类型与const类型混用时的编译错误

            //int const a = 10;
            //int const b = 20;
            //auto ret = min(a,b);
            //std::cout << "a : " << a << std::endl;
            //std::cout << "b : " << b << std::endl;
            //std::cout << "ret : " << ret << std::endl;
        }
        void test03() {
            //foo a,b;
            //auto ret = max(a,b); // 检查两次
            
        }
    }
    
}

int main() {
    //test::test01();
    test::v2::test02();


    return 0;
}