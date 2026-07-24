#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <map>

namespace test {
    
    namespace set_prac {
        void test01() {
        std::set<int> st;
        int a = 40;
            st.insert(20);
            st.insert({10,30});
            st.insert(std::move(a));
            for (const auto&i : st) {
                std::cout << i << " ";
            }
        auto ret1 = st.find(20);
            if (ret1 == st.end())
                std::cout << "20 not find" << std::endl;
            else
                std::cout << "find" << std::endl;
            ret1 = st.find(50);
            if (ret1 != st.end())
                std::cout << "find" << std::endl;
            else
                std::cout << "50 not find" << std::endl;
        std::pair<decltype(st)::iterator, bool> ret2 = st.insert(20);
            std::cout << "ret2 : " << *ret2.first << "  " << std::boolalpha << ret2.second << std::endl;
            ret2 = st.insert(60);         
            std::cout << "ret2 : " << *ret2.first << "  " << std::boolalpha << ret2.second << std::endl;
        //std::set<int,std::greater<int>> st2;
        auto cmp = [](int x, int y){return x > y;};
        std::set<int,decltype(cmp)> st2(cmp);
            st2.insert({10,20,30,40,50,60});
            std::cout << "ret : " << std::endl;
            for (const auto& i : st2) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    } // namespace set_prac
      
    namespace map_prac {
        void test01() {
        //std::map<std::string, int> mp; // 姓名升序
        std::map<std::string, int, std::greater<std::string>> mp; // 姓名降序
            mp["xiaoming"] = 20;
            mp["xiaohong"] = 30;
            mp["xiaogang"] = 40;
            for (auto& i : mp) {
                std::cout << i.first << " - "  << i.second << std::endl;
            }
            
        }

        void test02() {
            std::map<int ,std::string> mp;
            try {
                std::cout << "operator[]" << std::endl;
                mp[1] = "xiaoming";
                std::cout << "at()" << std::endl;
            auto ret = mp.at(1);
                std::cout << "find()" << std::endl;
            auto ret2 = mp.find(1);
                if (ret2 != mp.end()) {
                    std::cout << "*ret2 : " << ret2->first << " " << ret2->second << std::endl;
                } else {
                    std::cout << "not find" << std::endl;
                }
            } catch (...){
                std::cout << "Exception! : " << std::endl;
            }
            
        }
        
        void test03() {
            std::map<int, std::string> mp;
            mp.insert({1,"zhangsan"});
            mp.emplace(2,"lisi");
            for (auto& trans : mp) {
                std::cout << trans.first << "   " << trans.second << std::endl;
            }
        }
        
        void test04() {
            // count word in some sentences.
        std::map<std::string, int>mp;
        std::string trans;
            while (std::cin >> trans) {
                mp[trans] += 1;
            }
            for (const auto& w : mp) {
                std::cout << w.first << " : " << w.second << std::endl;
            }
        }


    } // namespace map_prac
    
    namespace unord_prac {// unordered_practice
        void test01() {
            
        }

    } // namespace unord_prac

} // namespace test

int main() {
    

    return 0;
}