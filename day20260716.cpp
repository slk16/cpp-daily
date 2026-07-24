#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>

namespace test {

    namespace v1{
        using std::vector;
        void test01() {
            vector<int> v;
            v.resize(10);
            //std::cout << "v.capacity() : " << v.capacity() << std::endl;
            std::iota(v.begin(), v.end(),1);
            for (const auto& trans: v) {
                std::cout << trans << " ";            
            }
            std::cout << std::endl;
            std::cout << "upper_bound : " << *std::upper_bound(v.begin(), v.end(), 5) << std::endl; // 6
            std::cout << "lower_bound : " << *std::lower_bound(v.begin(), v.end(), 5) << std::endl; // 5

        }
        void test02() {
            vector<int> v = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,};
            auto ret = std::equal_range(v.begin(), v.end(), 3);
            auto [lo, up] = std::equal_range(v.begin(), v.end(), 4);
            std::cout << "ret : " << std::distance(v.begin(), ret.first)<< "   " << std::distance(v.begin(), ret.second) << std::endl;
            std::cout << "distance of lo : " << std::distance(v.begin(), lo) << std::endl;
            std::cout << "disatnce of up: " << std::distance(v.begin(), up) << std::endl;
        }

        void test03() {
            vector<int> v = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,};
            bool ret1 = std::binary_search(v.begin(), v.end(), 3);
            std::cout << "ret1 : " << std::boolalpha << ret1 << std::endl; 
            bool ret2 = std::binary_search(v.begin(), v.end(), 10);
            std::cout << "ret2 : " << std::boolalpha << ret2 << std::endl; 
        }
    } // namespace v1
      
    namespace set_prac {
        void test01() {
            
        } 


    } // namespace set_prac


} // namespace test



int main () {

    return 0;
}