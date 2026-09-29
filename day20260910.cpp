#include <iostream>
#include <vector>
#include <numeric>


namespace test01 {
    template <typename E, std::size_t N>
    E* begin(E (&array)[N]) noexcept {
        return array;
    }
    template <typename Container>
    typename Container::iterator begin(Container& e) noexcept {
        return e.begin();
    }
    void test01() {
        std::vector<int> ivec(20, 0); 
        int arr[20];
        std::iota(ivec.begin(), ivec.end(), 20);
        std::iota(arr, arr + 20, 10);

        auto b1 = test01::begin(ivec);
        std::cout << "*b1 : " << *b1 << std::endl;
        auto b2 = test01::begin(arr);
        std::cout << "*b2 : " << *b2 << std::endl;
    }
    class foo {
    public:
    };
    class bar {
    public:
        static decltype(std::cout)& out;
    };
    decltype(std::cout)& bar::out = std::cout;
    template <typename T>
    void f(T){
        T::out << "hello world";
    }
    void test02() {
        f(bar{});
    }
} // namespace test

namespace test02 {
    using ret_t = int&;
    auto f() -> ret_t {
        int a = 20;
        return ret_t{a};//error
    }
    decltype(auto) g() { return f(); }
    void test01() {
        auto &&g_ret =
            static_cast<std::decay_t<decltype(g())>>(g()); // 测试手动退化
        int a = 20;
        decltype((g_ret)) name = a;
    }

} // namespace test02

int main() {
    test02::test01();
    
    return 0;
}