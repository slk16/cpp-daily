#include <iostream>
#include <regex>
#include <stdexcept>
#include <thread>
#include <variant>
#include <random>
#include <stdexcept>

namespace test01 {
    class func {
        int& i_;
    public:
        func(int& i) : i_(i) {}
        void operator()(){
            i_ += 30;
            std::cout << i_ << std::endl;
        };
    };
    
    class thread_guard {
    private:
        std::thread& th_;
    public:
        explicit thread_guard(std::thread& th) : th_(th) {}
        ~thread_guard() {
            if (th_.joinable()){
                th_.join();
            }
        }
        thread_guard(const thread_guard&) = delete;
        thread_guard& operator=(const thread_guard&) = delete;
    };
    void random_throw() {
        static std::random_device rd;
        if (rd() % 2){
            throw std::runtime_error{"random_throw"};            
        }
    }
    void test01() {
        std::cout << "begin test01()" << std::endl;
        int some_local_state = 0;
        func f{some_local_state};
        std::thread t{f};
        t.join();
        thread_guard tg{t};
        random_throw();
        //throw std::runtime_error{"err"};
        std::cout << "end test01()" << std::endl;
    }
} // namespace test01

namespace test02 {
    
    void test01() {
        std::variant<std::string, int> var = std::string{"hello"};
        std::cout << "var.index() : " << var.index() << std::endl;
        std::cout << "std::get() : " << std::get<std::string>(var) << std::endl;
    }
    void test02() {
        std::variant<int, std::string> var = 30;
        std::string str = "hello";
        var = std::string("hello");
        var = "world";
        int* ret = std::get_if<int>(&var);
        if (ret != nullptr) {
            std::cout << "matched : " << *ret << std::endl;
        } else {
            std::cout << "unmatched" << std::endl;
        }
    }
    void test03() {
        auto print_str = [](std::string str) {
            std::cout << str << std::endl;
        };
        auto print_regex_search = [](std::string str, std::regex re) {
            for (   std::sregex_iterator it{str.begin(), str.end(), re}, end;
                    it != end;
                    ++it) {
                std::cout << it->str() << " sep ";
            }
        };
        print_str("hello");
        print_regex_search("hello 123 world 456 end",std::regex(R"sep(\d+)sep"));
    }
    void test04() {
        std::variant<int, double, std::string> var = 3.14;
        var = "hello world";
        std::visit([](auto&& arg) { //if constexpr写法
            using T = std::decay_t<decltype(arg)>; 
            if constexpr(std::is_same_v<T, int>)
                std::cout << "int : " << arg << std::endl;
            else if constexpr(std::is_same_v<T, double>)
                std::cout << "double : " << arg << std::endl;
            else
                std::cout << "std::string : " << arg << std::endl;
        }, var);
        auto print_int =  [](int) { std::cout << 3 << std::endl;};
    }
    template <typename... Ts>
    struct overloaded : Ts... { 
        using Ts::operator()...;
    };
    template <typename... Ts> overloaded(Ts...) -> overloaded<Ts...>;
    void test05() {
        std::variant<int, double, std::string> var;
        var = "hi";
        std::visit(
            overloaded {
                [](int i) { std::cout << "int : " << i << std::endl; },
                [](double d) { std::cout << "double : " << d << std::endl; },
                [](std::string s) { std::cout << "std::string : " << s << std::endl; },
            }, var
        );
    }

} // namespace test02

namespace test03 {
    void test01() {
        
    }

} // namespace test03

int main() {
    try {
        test02::test04();        
    } catch (std::exception& e){
        std::cout << "test: " << e.what() << std::endl;
    }

    return 0;
}