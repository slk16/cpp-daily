#include <iostream>
#include <thread>
#include <stdexcept>
#include <chrono>

namespace test01 {
    class scoped_thread {
    public:
        explicit scoped_thread(std::thread th) :
            th_(std::move(th))
        { 
            if (!th_.joinable()) {
                throw std::logic_error("th_ is not joinable!");
            }
        }
        ~scoped_thread() {
            th_.join();
        }
        scoped_thread(const scoped_thread&) = delete;
        scoped_thread& operator=(const scoped_thread&) = delete;
    private:
        std::thread th_;
    };
    class func {
    int& i_;
    public:
        func(int& i) : i_(i) { }
        void operator()() {
            for (int i = 0; i < 10000; ++i) {
                i_ += 3;
            } 
            std::cout << "func() : " << i_ << std::endl;
        }
    };
    void test01() {
        int local_state = 30;
        scoped_thread sth{std::thread{func{local_state}}};
        std::this_thread::sleep_for(std::chrono::seconds{1});
        std::cout << "finish test01()" << std::endl;
    }
    template <unsigned N>
    struct Factorial {
        constexpr static unsigned value = N * Factorial<N - 1>::value;
    };
    template <>
    struct Factorial<1> {
        constexpr static unsigned value = 1;
    };

    void test02() {
        unsigned ret = Factorial<30>::value;
        std::cout << "ret : " << ret << std::endl;
    }
    class joining_thread {
    public:
        joining_thread() noexcept = default;
        template<typename Func, typename... Args>
        joining_thread(Func&& f, Args&&... args) :
            th_(std::forward<Func>(f), std::forward<Args...>(args)...) 
        {}
        joining_thread(joining_thread&& other) noexcept :
            th_(std::move(other.th_))
        {}
        joining_thread& operator=(joining_thread&& other) noexcept {
            if (this->th_.joinable())
                th_.join();
            this->th_ = std::move(other.th_);
            return *this;
        }
        explicit joining_thread(std::thread th) noexcept : 
            th_(std::move(th))
        {}
        joining_thread& operator=(std::thread th) noexcept {
            if (this->th_.joinable())
                this->th_.join();
            this->th_ = std::move(th);     
            return *this;
        }
        ~joining_thread() noexcept {
            if (th_.joinable())
                th_.join();
        }
        std::thread::id get_id() const noexcept {
            return this->th_.get_id();
        }
        void swap(joining_thread& other) noexcept{
            this->th_.swap(other.th_);
        }
        bool joinable() {
            return th_.joinable();
        }
        void join() {
            th_.join();
        }
        void detach() {
            th_.detach();
        }
        std::thread& as_thread() noexcept {
            return this->th_;
        }
        const std::thread& as_thread() const noexcept {
            return this->th_;
        }
    private:
        std::thread th_;
    };
    void calc(int n) {
        std::cout << n + 30 << std::endl;
    }
    
    void test03() {
        auto test = [](int n) {
            for (int i = 0; i < 300; ++i) {
                n += i;
            }
            std::cout << n << std::endl;
        };
        joining_thread jth(test, 20);
    }
} // namespace test01

int main() {
    test01::test03();
    
    return 0;
}