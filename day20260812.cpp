#include <iostream>
#include <random>
#include <memory>
#include <cstring>
#include <vector>
#include <numeric>
#include <chrono>
#include <thread>
#include <algorithm>
#include "head/val.hpp"

namespace test {
    namespace t1{
        void test00() {
            std::unique_ptr<int> iptr1 = std::make_unique<int>(20);
            std::unique_ptr<int> iptr2 = std::make_unique<int>(10);
            //std::memcpy(&iptr1, &iptr2, sizeof (iptr1));
            std::cout << "p1 : " << *iptr1 << std::endl;;
            std::cout << "p2 : " << *iptr2 << std::endl;;
        }
        [[noreturn]] void test01() {

            exit(0);
        }

        void test02() {
            slk::Val<int> val1(5);
            slk::Val<int> val2= val1;
            std::cout << val1.get_val() << std::endl;
            
        }
    }
    namespace t2 {
        namespace v1{
            template <typename InputIterator > [[nodiscard]]
            auto sum (InputIterator first, InputIterator last) {
                using value_type = std::remove_reference_t<decltype(*first)>;
                auto result = std::accumulate(first, last, value_type{});
                return result;
            }
        }
        namespace v2{
            template <typename InputIterator> [[nodiscard]] 
            auto sum(InputIterator first, InputIterator last) {
                using value_type = typename InputIterator::value_type;
                using diff_type = typename InputIterator::difference_type;
                diff_type count = std::distance(first,last);
                if (count > 1024000) {
                    auto num_thread= std::thread::hardware_concurrency();       
                    std::size_t chunk_size = count / num_thread;
                    std::size_t remainder = count % num_thread;
                    std::vector<std::thread> threads;
                    std::vector<value_type> results(num_thread, value_type{});

                    auto itl = first;
                    for (std::size_t i = 0; i < num_thread; ++i) {
                        auto itr = std::next(itl, ( chunk_size + ( i < remainder ? 1 : 0)));
                        threads.emplace_back([itl, itr, &results, i](){
                            results[i] = std::accumulate(itl, itr, value_type{});
                        });
                        itl = itr;
                    }
                    for (auto& thread : threads) {
                        thread.join();
                    }
                    return std::accumulate(results.begin(), results.end(), value_type{});
                }
                auto result = std::accumulate(first, last, value_type{});
                return result;
            }
        }

        void test01() {
            std::vector<int> iv(100000000);
            std::mt19937 gen(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, 9);
            std::generate(iv.begin(), iv.end(), [&dist, &gen]() {return dist(gen);});
            using clk = std::chrono::steady_clock;
            decltype(clk::time_point()) b,e;
            decltype(e - b) time;
            decltype(v1::sum(iv.begin(), iv.end())) result;

            std::cout << " --- v1::sum() ---" << std::endl;
            b = clk::now();
            result = v1::sum(iv.begin(), iv.end());
            e = clk::now();

            time = e - b;
            std::cout << "time : " << time.count() << std::endl;
            std::cout << "result : " << result << std::endl;
            
            std::cout << " --- v2::sum() ---" << std::endl;
            b = clk::now();
            result = v2::sum(iv.begin(), iv.end());
            e = clk::now();

            time = e - b;
            std::cout << "time : " << time.count() << std::endl;
            std::cout << "result : " << result << std::endl;
        }
        void test02() {
            size_t size = std::thread::hardware_concurrency();
            std::cout << "size : " << size << std::endl;
        }
    }
} // namespace test


int main() {
    using namespace test::t1;
    test02();

    return 0;
}