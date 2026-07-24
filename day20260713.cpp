#include <iostream>
#include <string>
#include <type_traits>
#include <stdexcept>

namespace test {
template<typename T>
T safe_divide(T a,T b) {
    static_assert(std::is_arithmetic<T>::value, "no type matched");
    if constexpr (std::is_integral<T>::value) {
        if (b == 0)
            throw std::runtime_error("a is divided by zero");
        return a / b;
    } else if constexpr (std::is_floating_point<T>::value) {
        return a / b;                
    }
}

namespace v1 {

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>,std::string>
to_string(T val) {
    return std::to_string(val);
}

template <typename T>
std::enable_if_t<!std::is_arithmetic_v<T>, std::string>
to_string(T val) {
    return "not a number";

}

} // namespace v1

namespace v2 {

template <typename T>
std::string to_string(T val,typename std::enable_if<std::is_arithmetic_v<T>, T>::type = 0) {
    return std::to_string(val);
}

template <typename T>
std::string to_string (T val, typename std::enable_if<!std::is_arithmetic<T>::value, int>::type = 0) {
    return "NaN";
}

} // namespace v2

namespace v3 {
    
template <typename T>
std::string to_string(T val, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0) {
    return std::to_string(val);
}

template <typename T>
std::string to_string(T val, std::enable_if_t<!std::is_arithmetic_v<T>, int> = 0) {
    return "NaN";
}



} // namespace v3

namespace v4 {
    struct arithmetic_tag{};
    struct non_arithmetic_tag{};
    namespace impl {

        template <typename T>
        std::string to_string_impl(T val, arithmetic_tag) {
            return std::to_string(val);
        }

        template <typename T>
        std::string to_string_impl(T val, non_arithmetic_tag) {
            return "Not a number";
        }
    }
    template <typename T>
    std::string to_string(T val) {
        using tag_t = std::conditional_t<std::is_arithmetic_v<T>, arithmetic_tag, non_arithmetic_tag>;
        return impl::to_string_impl(val, tag_t());
    }
}



} // namespace test

using namespace test;
void test01() {
    auto ret1 = safe_divide(10, 2);
    std::cout << "ret1 : " << ret1 << std::endl;
    auto ret2 = safe_divide(10.0,2.0);
    std::cout << "ret2 : " << ret2 << std::endl;
    try {
        auto ret3 = safe_divide(10,0);
        std::cout << "ret3 : " << ret3 << std::endl;
    } catch ( std::exception& e) {
        std::cout << "Exception ! : "<< e.what() << std::endl;        
    }
    try {
        auto ret4 = safe_divide(10.0,0.0);
        std::cout << "ret4 : " << ret4 << std::endl;
    } catch ( std::exception& e) {
        std::cout << "Exception ! : "<< e.what() << std::endl;        
    }
    //auto ret3 = safe_divide("string", "hello");
    //std::cout << "ret3 : " << ret3 << std::endl;
}

void test02() {
    int a = 10;
    double b = 3.14;
    std::string str = "hello";
    std::cout << "string : " + test::v4::to_string(a) << std::endl;
    std::cout << "string : " + test::v4::to_string(b) << std::endl;
    std::cout << "string : " + test::v4::to_string(str) << std::endl;
}

int main() {
    test02();
    

    return 0;
}