#include <iostream>
#include <thread>
#include <numeric>
#include <vector>
namespace test {
    namespace t1{
        // 神秘bug尽量不要在类中使用引用
        struct foo {
            int val1;
            int& ref_val2;
            foo(int& ref) : val1(ref), ref_val2(val1) {}
            void operator()() const { 
                std::cout << "val1 : " << val1 << std::endl;
                std::cout << "ref_val : " << ref_val2 << std::endl;
            };
        };
        struct bar {
            int val1;
            int& val2;
            int* val3;
            //bar() : val2(val1), val1(30) {}; // 顺序不对，引发编译器警告
            bar() : val1(3), val2(val1), val3(&val2) {};
        };
        void test01() {
            std::cout << " --- test01() --- " << std::endl;
            int val = 20;
            auto change = [&val]() {val = 30;};
            std::cout << "val : " << val << std::endl;
            change();
            std::cout << "val : " << val << std::endl;
        }
        void test02() {
            std::cout << " --- test02() --- " << std::endl;
            int a = 20;
            std::cout << a << std::endl;
            const foo val = a;        
            //val.val1 = 20;
            std::cout << "val.ref_val2 = 20" << std::endl;
            val.ref_val2 = 20;
            val();
            std::cout << "val.ref_val2 = 30" << std::endl;
            val.ref_val2 = 30;
            val();
        }
        void test03() {
            std::cout << " --- test03() --- " << std::endl;
            bar a;
        }
        void test04() {
            std::cout << " --- test04() --- " << std::endl;
            //const int a = 20;
            //int& ref = a;
            const int a = 20;
            class write {
                write(int& val) {
                    val = 30;
                }
            };
            //write(a); // 这不行
        }
        void test05() {
            const int a = 20;
            auto& ref = a;
            // const_cast<int>(a) = 10; // error
            // const_cast // 只能去除底层const，用来兼容c接口
            // 只有const_cast能移除cv限定符
            const int* cip= &a;//去除了底层const
            int* ip = (int*)cip;//只有const_cast才能用来去除底层const
            
        }
        void test06() {
            // 出乎意料，还能有中文变量名，不过不推荐中文变量名
            //int 二十 = 20;
            //std::cout << 二十 << std::endl;
        }
    }
    namespace t2{
        // a function to accumulate using multi threads
        template <typename InputIterator>
        auto sum(InputIterator first, InputIterator last) {
            
            auto result = std::accumulate(first, last, typename std::remove_reference<decltype(*first)>::type()); //等价于 std::remove_reference_t<decltype(*first)>(0)
            return result;
        }
        void test01() {
            std::vector<int> iv;
            iv = { 1,2,9,3,4,5};
            std::cout << sum(iv.begin(), iv.end()) << std::endl;
        }
    }
    namespace t3{
        template <bool, typename T = void>
        struct enable_if {};
        template <typename T>
        struct enable_if<true, T> {
            using type = T;
        };
        template <bool Cond, typename T>
        using enable_if_t = typename enable_if<Cond, T>::type;

        template <typename T>
        std::string to_string(T val, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0) {
            return std::to_string(val);
        }
        template <typename T>
        std::string to_string(T val, std::enable_if_t<!std::is_arithmetic_v<T>, int> = 0) {
            return "NaN";   
        }
        void test01() {
            namespace ts = test::t3;
            int ival = 5;
            std::string sval = "hello";
            std::cout << "int 5 to_string : " << (ts::to_string(ival)) << std::endl;             
            // std::cout << "std::string \"hello\" to_string : " << (ts::to_string(sval)) << std::endl;
            // 上面编译出错
        }
    }
    namespace t4 {
        void test01() {
        }
    }
}

int main() {
    //test::t1::test01();
    //test::t1::test02();
    //test::t1::test03();
    //
    //test::t1::test06(); 



    return 0;
}