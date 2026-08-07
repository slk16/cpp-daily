#include <iostream>
#include "proj/json/json.cpp"


namespace test {
    namespace func_test {
        void test01();
    }
    namespace v2 {
        void test01();
    }
    void test01();
}
int main() {
    using namespace test;
    test::test01();

    return 0;
}
namespace test {
    void test01() {
        using namespace json::v1;
        Json a;
    }

    namespace func_test{
        int i = 30;
        //void vr(int a) {
        //    std::cout << "vr" << std::endl;
        //}
        
        //    namespace std {
        //} // 这会阻止非限定名称查找
        void cout() {}

        class vr {
        public:
            vr(int i){
                std::cout << "vr _ class vr(int) : " << i << std::endl;
            }
            void test(int i) {
                this->i = 10;
                std::cout << i << std::endl;
                std::cout << this->i << std::endl;
                std::cout << test::func_test::i << std::endl;
            }
            int i;
        };
        std::ostream& operator<<(std::ostream& out, const vr&) {
            std::cout << "class vr" << std::endl;
            return out;
        }
        //void vr(char& a) {
        //    std::cout << "vr _ char& a" << a << std::endl;
        //}
        //void vr(const char& a) {
        //    std::cout << "vr _ const char " << a << std::endl;
        //}
        //void vr(const int& a) {
        //    std::cout << "vr _ const& : " << a << std::endl;
        //}
        //void vr(int& a) {
        //    std::cout << "vr _ & : " << a << std::endl;
        //}
        //void vr(int&& a) {
        //    std::cout << "vr _ && : " << a << std::endl;
        //}
        void test01() {
            vr(10);
        }
    }
    namespace v2 {

        void test01() {
            int a = 10;
            int& lrefa = a;
            int& lreffa = lrefa;
            std::cout << "lrefa : " << lrefa << std::endl;
            std::cout << "lreffa : " << lreffa << std::endl;
        } // 引用
        void test02() {

        }
    }
} // namespace test