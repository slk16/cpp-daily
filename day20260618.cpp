#include <iostream>
#include <string>
#include <vector>
int main() {
    std::vector<int> v1;
    std::vector<int> v2(10,42);
    std::vector<int> v3{10,42};
    std::vector<std::string> v4{10, "hi"};
    std::cout << "v1.size() is " << v1.size() << std::endl;
    std::cout << "v2.size() is " << v2.size() << std::endl;
    std::cout << "v3.size() is " << v3.size() << std::endl;
    std::cout << "v4.size() is " << v4.size() << std::endl;


    return 0;
}