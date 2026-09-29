#include <iostream>

namespace test01{
    template <typename T1, typename T2>
    auto max(T1 a, T2 b) {
        return b < a ? a : b;
    }

    template <typename RT, typename T1, typename T2>
    RT max(T1 a, T2 b) {
        return b < a ? a : b;
    }
    void test01() {
        
    }
}
namespace test02{
    struct A {
        typedef int AT;
        void f1(AT);
        void f2(float);
        //template <class T> void f3();
    };

    struct B {
        typedef char AT;
        typedef float BT;
        friend void A::f1(AT);   // #1
        friend void A::f2(BT);   // #2
        //friend void A::f3<AT>(); // #3
    };
} // namespace test02
namespace test03 {

} // namespace test03

int main() {


    return 0;
}