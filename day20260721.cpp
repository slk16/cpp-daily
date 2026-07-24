#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <random>
#include <list>

namespace test {
    namespace v1 {
        void test01() {
        std::multiset<int> mst;

            {
            std::vector<int> temp = { 1,2,3,4,5,6,7};
                std::cout << "insert : ";
                for (const auto& trans : temp) {

                std::multiset<int>::iterator ret = mst.insert(trans);
                    std::cout << *ret << " ";
                }
                std::cout << std::endl;
            }

            auto print = [&mst](){
                std::cout << "range for : ";
                for (const auto& trans : mst) {
                    std::cout << trans << " ";                
                }
                std::cout << std::endl;
            };
            
            mst.insert(2);
            mst.insert(2);
            mst.insert(2);
            mst.insert(2);

            auto ret1 = mst.insert(2);

            {
                std::cout << "mst.count : " << mst.count(2) << std::endl;
            }
            print();

            mst.erase(ret1);
            print();
            
            mst.erase(2);
            print();

        } // test01()

        void test02() {
            auto random_string = []() -> std::string {
                //
                static std::default_random_engine e(std::random_device{}());
                static std::uniform_int_distribution<int> u(0, 1024);
                std::string ret;
                int count = u(e) % 30 + 5;
                //
                for (int i = 0; i < count; ++i) {
                    ret.push_back('a' + u(e) % 26);
                }
                return ret;
            };
            
            std::multimap<int, std::string> mp; // [var]
            auto print = [&mp]() {for (const auto& trans : mp) std::cout << trans.first << " -> " << trans.second << std::endl;};
            for (int i = 1; i <= 15; ++i) {
                mp.emplace(i, random_string());
            }
            mp.insert({3, random_string()});
            mp.insert({3, random_string()});
            mp.insert({3, random_string()});
            print();

            auto print_range = [&mp](std::pair<std::multimap<int,std::string>::iterator,std::multimap<int,std::string>::iterator> range) {
                for (auto it = range.first; it != range.second; ++it) {
                    std::cout << it->first << " -> " << it->second << std::endl;
                }
            };
            std::cout << "print_range : " << std::endl;
            auto erange = mp.equal_range(3);
            print_range(erange);
        }
    } // namespace v1
    
    namespace v2 {
        void test01() {
            std::list<int> lt1 = {1,3,5,7};
            std::list<int> lt2 = {2,4,6,8};
            
        }

    } // namespace v2
    

} // namespace test

int main() {
    std::cout << " --- test01() : --- " << std::endl;
    test::v1::test01();
    std::cout << " --- test02() : --- " << std::endl;
    test::v1::test02();

    return 0;
}
