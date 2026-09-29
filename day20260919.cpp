#include <iostream>
#include <thread>
#include <random>
#include <cstdint>

namespace test {
    
    void do_work(std::size_t id) {
        std::cout << "id : " << id << std::endl;
        int ret = 0;
        for (int i = 0; i < 100000; ++i) {
            ret += i;
        }
        std::cout << "id : " << id << " ret : " << ret << std::endl;
        std::cout << "id : " << id << " finish" << std::endl;
    }
    void test01() {
        std::vector<std::thread> ths;
        std::size_t size = std::thread::hardware_concurrency();
        for (std::size_t i = 0; i < size; ++i) {
            ths.emplace_back(do_work, i + 1);    
        }
        for (auto& t : ths) {
            t.join();
        }
    }
    template <typename Iterator, typename T>
    struct accumulate_block {
        void operator()(Iterator first, Iterator last, T& init) {
            init = std::accumulate(first, last, init);            
        }
    };
    template <typename Iterator, typename T>
    T parallel_accumulate(Iterator first, Iterator last, T init){
        uint64_t const length = std::distance(first, last);
        if (!length)
            return init; 
        uint64_t const hard_threads = std::thread::hardware_concurrency();
        uint64_t const min_per_thread = 25;
        uint64_t const max_threads = (length + min_per_thread - 1) / min_per_thread;
        uint64_t const num_threads = 
            std::min(hard_threads != 0 ? hard_threads : 2, max_threads);
        std::vector<T> results(num_threads);
        std::vector<std::thread> threads {num_threads - 1 };
        uint64_t block_size = length / num_threads;
        Iterator block_start = first;
        for (uint64_t i = 0; i < num_threads - 1; ++i) {
            Iterator block_end = block_start; 
            std::advance(block_end, block_size);
            threads[i] =
                std::thread{accumulate_block<decltype(block_start), T>{},
                            block_start, block_end, std::ref(results[i])};
            block_start = block_end;
        }
        accumulate_block<decltype(block_start), T>{}(block_start, last, results[num_threads - 1]);
        for (auto& th : threads) {
            th.join();
        }
        return std::accumulate(results.begin(), results.end(), T{});
    }
    void test02() {
        std::vector<int> data = []() -> std::vector<int> {
            std::vector<int> ret;
            static std::default_random_engine e{ std::random_device{}() };
            static std::uniform_int_distribution u(0, 3);
            for (int i = 0; i < 1000;++i) {
                ret.push_back(u(e));                
            }
            return std::move(ret);
        }();
        auto std_result = std::accumulate(data.begin(), data.end(), 0);
        auto my_result = parallel_accumulate(data.begin(), data.end(), 0);
        std::cout << "std_result : " << std_result << std::endl;
        std::cout << "my_result : " << my_result << std::endl;
        if (std_result != my_result) {
            std::cout << "result is not same!" << std::endl;
        } else {
            std::cout << "result is same =) " << std::endl;
        }
    }
    class C {};    
    void g(...) {
        std::cout << "g(...)" << std::endl; 
    };
    void g(C&&) {
        std::cout << "g(C&&)" << std::endl; 
    };
    template <typename T>
    void fwd(T&& arg) {
        g(std::forward<T>(arg));
    }
    void test03() {
        C c;
        g(std::move(c));
    }

} // namespace test

int main() {
    test::test03();
    
    return 0;
}