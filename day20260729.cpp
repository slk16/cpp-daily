#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main() {
    std::string a;
    auto ret = a.find('a');
    auto it = std::find(a.cbegin(), a.cend(), 'a');
//    if (ret == a.end())
//        std::cout << "not find a" << std::endl;
//  find返回的不是迭代器，显然是历史遗留问题
    std::vector<int> v;
    auto ret2 = std::find(v.begin(), v.end(), 20);
    if (ret2 == v.end() )
        std::cout << "not find 20" << std::endl;



    return 0;
}