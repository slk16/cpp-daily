#include <iostream>
#include <string>
#include <cstdint>
#include <type_traits>

namespace test {
class net_error: public std::runtime_error {
public:
    net_error(const char* msg): std::runtime_error(msg) {};
    const char* what() const noexcept{
        return std::runtime_error::what();
    }
};

class timeout_error: public test::net_error {
public:
    timeout_error(const char* msg): net_error(msg) {};
    const char* what() const noexcept{
        return net_error::what();
    }
};

void test01() {
    try {
        int option = 0;
        std::cout << "Enter your option:" << std::endl;
        std::cin >> option;
        switch(option) {
        case 1 : throw std::runtime_error("runtime_error");break;
        case 2 : throw test::net_error("net_error");break;
        case 3 : throw test::timeout_error("timeout_error");break;
        }
        std::runtime_error re{ "runtime_error!"};
        throw re;
    } catch (std::runtime_error& re){
        std::cout << "Exception!! : " << re.what() << std::endl;
    }
}

template <typename T>
std::string format_value (T val) {
    if constexpr (std::is_integral<T>::value)
        return "int : " + std::to_string(val);
    else if constexpr (std::is_floating_point<T>::value)
        return "float : " + std::to_string(val);
    else if constexpr (std::is_pointer<T>::value)
        return "pointer : " + std::to_string(reinterpret_cast<std::uintptr_t>(val));
    else if constexpr (std::is_class_v<T>)
        return "class !";
    else if constexpr (std::is_union_v<T>)
        return "union !";
    else 
        return "unknown type";
}

} // namespace test

namespace prac {

// test2
class Animal {
public:
    
};
class Cat : public Animal {

};
class Dog : public Animal {

};
} // namespace prac

int main() {
    int a = 10;
    float b = 3.14f;
    double c = 3.0;
    prac::Animal d;
    
    std::cout << test::format_value(a) << std::endl;
    std::cout << test::format_value(b) << std::endl;
    std::cout << test::format_value(c) << std::endl;
    std::cout << test::format_value(d) << std::endl;
    std::cout << test::format_value(std::string("hello")) << std::endl;

    return 0;
}