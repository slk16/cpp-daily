#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
namespace test {
    namespace t1 {
        void test01() {
            std::vector<double> times = {1,6e1,3.6e3,8.64e4,2.592e5,9.4608e7,9.4608e9};
            auto callgn = [](double time) {     
                return time;
            };
            auto calsqrtn = [](double time) -> double {
                return time * time;
            };
            auto caln = [](double time) -> double{
                return time;
            };
            auto print_ret = [&times](auto cal){
                std::cout << "result : ";
                for (auto trans : times) {
                    std::cout.width(8);
                    std::cout.setf(std::ios::scientific);
                    std::cout << cal(trans) ;
                }
                std::cout << std::endl;
            };
            print_ret(callgn);
            print_ret(calsqrtn);
            print_ret(caln);            
        }
    } // namespace t1
      // 
    namespace t2 {
        template <typename T>
        T max(T& a, T& b) {
            return b < a ? a : b; 
        }
        void test01() {
            int a = 10;
            int b = 10;
            auto ret = max(a,b);
            std::cout << ret;
        }
        void test02() {

        }
    }
    
} // namespace test

int main() {
    test::t1::test01();

    


    return 0;
}