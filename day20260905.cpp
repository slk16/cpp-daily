#include <cinttypes>
#include <iostream>
#include <limits>

namespace test01 {
    class foo {
    public:
        foo(const foo& other) = delete;
        foo(foo&& other) = delete;
        foo(unsigned val = 10) : data_(new int[(val > 0 ? val : 1)]) {
        }
        int& get() const noexcept {
            return *data_;
        }
        ~foo() {
            delete[] data_;
        }
        int* data_;
    };
    void swap(foo& a, foo& b) {
        int* temp = a.data_;
        a.data_ = b.data_;
        b.data_ = temp;
    }//foo类型高效swap
    void test02() {
        using namespace std;
        int inta = 10, intb = 20;
        //swap(inta, intb); // swap阻挡
    } 
    void test01() {
        using std::swap;
        foo fooa; 
        foo foob;
        swap(fooa, foob);//通过adl查找，找不到fallback to std::swap

        int inta = 10;
        int intb = 20;
        //swap(a,b);//查不到
        swap(inta,intb);
    }
}
namespace test02 {
    
    class foo {
    public:
        foo(const foo& other) = delete;
        foo(foo&& other) = delete;
        foo(unsigned val = 10) : data_(new int[(val > 0 ? val : 1)]) {
        }
        int& get() const noexcept {
            return *data_;
        }
        ~foo() {
            delete[] data_;
        }
        int* data_;
        friend void swap(foo& a, foo& b) {
            int* temp = a.data_;        
            a.data_ = b.data_;
            b.data_ = temp;
        }
    };
    inline void test01() {
        using namespace std;
        //using std::swap;
        
        int ia = 10, ib = 20;
        swap(ia, ib);
        
        foo a, b;
        swap(a, b);
    }
    void test02() {
        /* namespace test01中test02的写法使用户定制版阻碍了Usual-unqualified lookup
        * using-declaration的写法对用户太过繁琐 
        * using std::swap配合swap(a,b)一不小心就会写成std::swap
        * 就使用std::swap中的低效实现
        * using namespace std;实现adl二段式由于名字隐藏直接挂
        * hidden friend 可以解决这个问题，可是
        *
        * 
        */ 
    }
}
namespace test03 {

}

int main() {
    test01::test01();


    return 0;
}