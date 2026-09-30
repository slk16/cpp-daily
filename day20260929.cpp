#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <stack>
#include <limits>
#include <memory>
#include <exception>
#include <random>

namespace test {
    struct empty_stack : std::exception {
    public:
        const char* what() { return "The stack is empty"; };
    };
    template <typename T>
    class Threadsafe_stack {
    public:
        Threadsafe_stack() {}
        Threadsafe_stack(Threadsafe_stack<T> const& other) {
            std::unique_lock<std::mutex> uni_lock{other.m_};                        
        }
        Threadsafe_stack& operator=(Threadsafe_stack const&) = delete;
        void push(const T& elem) {
            std::unique_lock<std::mutex> lock{this->m_ };
            st_.push(std::move(elem));
        }
        void pop(T& ret) {
            std::unique_lock<std::mutex> lock{ this->m_ };
            if (!st_.empty()) {
                ret = std::move(this->st_.top());
                this->st_.pop();
                return ret;
            }
            throw empty_stack{};
        }
        std::shared_ptr<T> pop() {
            std::unique_lock<std::mutex> lock{ this->m_ };
            std::shared_ptr<T> pret;
            if (!st_.empty()) {
                pret = std::make_shared<T>(std::move(this->st_.top()));                
                this->st_.pop();
                return pret;     
            }           
            throw empty_stack{};
        }
        bool empty() {
            std::unique_lock<std::mutex> lock{ this->m_ };            
            return this->st_.empty();
        }
    private:
        std::stack<T> st_;
        mutable std::mutex m_;
    };
    template <typename Type, std::size_t Times> 
    void test_multi() {
        static std::default_random_engine e{std::random_device{}()};
        static std::uniform_int_distribution u(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        Threadsafe_stack<int> st;
        auto random_op = []() {

        };
        
        auto random
        for (int i = 0; i < Times; ++i) {

        }
    }

} // namespace test

int main() {



    return 0;
}