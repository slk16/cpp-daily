#include <iostream>
#include <vector>

namespace test {
template <typename T>
std::string_view type_name() {
    if constexpr (std::is_integral<T>::value) {
        return "integral";
    } else if constexpr (std::is_floating_point<T>::value){
        return "floating_point";
    } else if constexpr (std::is_pointer<T>::value) {
        return "pointe";
    } else if constexpr (std::is_class<T>::value) {
        return "class";
    } else if constexpr (std::is_enum<T>::value) {
        return "enum";
    } else if constexpr (std::is_union<T>::value) {
        return "union";
    }
    return "";
}
enum class Num {
    First,
    Second,
    Third
};

void test01() {
    std::cout << "vector : " << type_name<std::vector<int>>() << std::endl;
    std::cout << "int : " << type_name<int>() << std::endl;
    std::cout << "bool : " << type_name<bool>() << std::endl;
    std::cout << "float : " << type_name<float>() << std::endl;
    std::cout << "enum : " << type_name<Num>() << std::endl;
}

} // namespace test

using namespace test;
int main() {
    test::test01();

    


    return 0;
}