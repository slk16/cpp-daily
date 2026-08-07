#include <iostream>
#include <vector>

namespace test{
    namespace t1 {
        template <typename T>
        T max(T a, T b) {
            return b < a ? a : b;
        }
        template <typename T1, typename T2>
        auto add(T1 a, T2 b) {
            return a + b;
        }//可以推导
        void test01() {
            {
                int a = 10;
                int& b = a;
                auto ret = max(a, b);
            }
            {
                int w = 10;
                int&a = w;
                int const & b = 10;
                auto ret2 = max(a, b);
            }
            {
                int a = 10;
                int& b = a;
            }
        }
        void test02() {
            double ret = add(1,4.2);
            std::cout << ret << std::endl;
        }
    }
    namespace t2 {
        template <typename T1, typename T2, typename RT>
        RT add(T1 a, T2 b) {
            return a + b;
        }
        void test01() {
            // auto ret = add(1,4.2); // 无法通过函数调用上下文推导模板参数的返回值类型
            auto ret = add<int,double,double>(1, 4.2); //可以显式指明类型
        }
    }
    namespace t3{
        //template <typename T1, typename T2>
        //auto add(T1 a, T2 b) {
        //    return a + b;
        //} //可以完全不指定返回类型
        
        template <typename T1, typename T2>
        auto add(T1 a, T2 b) -> decltype(a + b)
        {
            return a + b;
        }
        void test01() {
            auto ret = add(1,2.0);
            std::cout << ret << std::endl;
        }
        void test02() {

        }
    }
} // namespace test

int main() {
    test::t3::test01();
        
    

    return 0;
}