#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <iomanip>
#include <array>
#include <forward_list>

namespace test {
    
    namespace p1 {
        void test01() {
            std::unordered_set<int> st;
            st = {1,2,3,4,5,6};
            std::cout << "st.bucket_count() : " <<  st.bucket_count() << std::endl;
            std::cout << "st.bucket_size(st.bucket(3)) : " << st.bucket_size(st.bucket(3)) << std::endl;
            std::cout << "st.bucket(3) : " << st.bucket(3) << std::endl;
            std::cout << "st.max_bucket_count() : " << st.max_bucket_count() << std::endl;
        }
        
        void test02() {
            std::unordered_set<int> st;
            std::vector<int> vec1(10);
            std::iota(vec1.begin(), vec1.end(), 2);
            st.insert(vec1.begin(), vec1.end());
            std::cout << "st.load_factor() : " << st.load_factor() << std::endl;
            std::cout << "st.max_load_factor() : " << st.max_load_factor() << std::endl;
            std::cout << "st: ";
            for (const auto& trans : st) {
                std::cout << trans << " ";
            }
            std::cout << std::endl;
        }
        
        void test03() {
            std::unordered_map<std::string, int> ump;
            std::string trans;
            while (std::cin >> trans) {
                ump[trans] += 1;
            }
            std::cout << "count for words" << std::endl;
            for (const auto & pair: ump) {
                std::cout << pair.first << " : "  << pair.second << std::endl;
            }
        }
        
        void test04() {
            std::unordered_map<int,int> ump;
            auto bc = ump.bucket_count();
            std::cout << "start : bucket_count : " << bc << std::endl;
            //ump.reserve(100);
            //std::cout << "reserve : bucket_count : " << (bc = ump.bucket_count()) << std::endl;
            for (int i = 0; i < 100; ++i) {
                ump.emplace(i,i);
                if (bc != ump.bucket_count()) {
                    std::cout << "time : " << i << "  bucket_count : " << bc << " -> " << ump.bucket_count() << std::endl;                     
                    bc = ump.bucket_count();
                }
            }
            std::cout << std::endl;
        }

        void test05() {
        std::set<int> st;
        std::unordered_set<int> ust;
        constexpr int times = 10000000;
        std::default_random_engine e(std::random_device{}());
        std::uniform_int_distribution u(-10240, 10240);

        auto begin_time = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < times; ++i) {
                st.insert(u(e));
            }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto dtime1 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time);
            begin_time = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < times; ++i) {
                ust.insert(u(e));
            }
            end_time = std::chrono::high_resolution_clock::now();
        auto dtime2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time);
            std::cout << "duration time 1 : " << dtime1.count() << std::endl;
            std::cout << "duration time 2 : " << dtime2.count() << std::endl;
        }
    } // namespace p1
      
    namespace p2 {
        void print(const int* arr, int n) {
            std::cout << "print : ";
            for (int i = 0; i < n; ++i) {
                std::cout << arr[i] << " - ";
            }
            std::cout << "end" << std::endl;
        } 

        void test01() {
            std::array<int, 10> arr;
            std::iota(arr.begin(), arr.end(), 1);
            std::cout << "range-for : ";
            for (const auto& trans : arr) {
                std::cout << trans << " ";
            }
            std::cout << std::endl;
            arr.fill(0);
            std::cout << "range-for : ";
            for (const auto& trans : arr) {
                std::cout << trans << " ";
            }
            std::cout << std::endl;
            std::iota(arr.begin(), arr.end(), 10);
            std::cout << "range-for : ";
            for (const auto& trans : arr) {
                std::cout << trans << " ";
            }
            std::cout << std::endl;
            std::sort(arr.begin(), arr.end(), std::greater<int>());
            print(arr.data(), arr.size());
            try {
                std::cout << "access element at 15" << std::endl;
                std::cout << " element : " << arr.at(15) << std::endl;
            } catch (std::exception& e){
                std::cout << "Exception : " << e.what() << std::endl;
            }
        }
        
        template <typename T>
        void print_range(const T& container) {
            std::cout << "range_for : ";
            for (const auto& trans : container) {
                std::cout << trans << " ";
            }
            std::cout << std::endl;
        }
        void test02() {
            std::forward_list<int> fl = {1,2,3,4,5};
            print_range(fl);
            fl.push_front(-2);
            print_range(fl);
            fl.insert_after(fl.before_begin(), -10);
            print_range(fl);
            auto tit = std::find(fl.begin(), fl.end(), 3);
            fl.insert_after(tit, 99);
            print_range(fl);
            fl.erase_after(++tit);
            print_range(fl);
        }
        
        void test03() {
             
        }

    } // namespace p2
    

} // namespace test

int main() {


    return 0;
}