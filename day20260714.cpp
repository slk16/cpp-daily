#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <functional>

namespace test {
    namespace v1 {
        void print_all(){};

        template <typename T, typename... Args>
        void print_all(T first, Args... args) {
            std::cout << first << " -> ";
            print_all(args...);
        }

    } // v1
    
    namespace v2 {
        
        template <typename T>
        auto sum_all(T val) ->decltype (val) {
            return val;
        }
        
        template <typename T,typename... Args>
        auto sum_all(T first, Args... args){
            return first + sum_all(args...);
        } 
    }
    
    namespace v3 {
        template <typename... Args>
        auto sum_all(Args... args) {
            return (args + ...);
        }

        template <typename... Args>
        void print_all(Args... args) {
            ((std::cout << args << " -> "), ...);
            std::cout << "end\n";
        }
    } // v3
    

    namespace v4 {
        class Data {

        public:
            Data();
            Data(int val);
            Data(const Data& other);
            Data(Data&& other);
            ~Data(){};
        private:
            int data;
        };

        Data::Data() : data(0) {};

        Data::Data(int val) : data(val) {}

        Data::Data(const Data &other) { 
            data = other.data; 
            std::cout << "Construct by copy" << std::endl;
        }
        Data::Data(Data &&other) { 
            data = other.data; 
            std::cout << "Construct by move" << std::endl;
        }
        
        template <typename T>
        std::unique_ptr<Data> make_data(T&& val) {
            return std::make_unique<Data>(std::forward<T>(val));            
        }
        void test() {

            Data a(10);

            std::cout << "test 1 " << std::endl;
            auto p1 = make_data(std::move(a)); //move
            std::cout << "test 2 " << std::endl;
            auto p2  = make_data(a); // copy
            std::cout << "---------" << std::endl;
            
        }

    } // namespace v4
    
    namespace v5 {
        void test01() {
            int a = 10, b = 20;
            auto add= [=](){
                // a = 10; // lambda operator()默认为const函数
                return a + b;
            };
            std::cout << "ret : " << add() << std::endl;
            std::cout << "a : " << a << std::endl
                      << "b : " << b << std::endl;
        }
        
        void test02() {
            int a = 10, b = 20;
            auto add = [&]() {
                a = 20;
                b = 20;
                return a + b;
            }; 
            std::cout << "ret : " << add() << std::endl;
            std::cout << "a : " << a << std::endl
                      << "b : " << b << std::endl;
        }
        
        void test03() {
            int a = 10, b = 20;
            int c = 30;
            auto add = [=](int c) {
                // a = 20; // error // 加上mutable后才可以
                c = 40; // 可以修改              
                std::cout << "parameter c = 40" << std::endl;
                return a + b + c;
            };
            int ret = add(c);
            std::cout << "ret : " << ret << std::endl;
            std::cout << "a : " << a << std::endl
                      << "b : " << b << std::endl
                      << "c : " << c << std::endl;
        }
        
        void test04() {
            // 泛型lambda
            using std::string;
            auto add = [](auto a, auto b) -> decltype(a + b) { return a + b; };
            
            std::cout << "add(20, 30) : " << add(20, 30) << std::endl;
            std::cout << "add(3.14, 4.96) : " << add(3.14, 4.96) << std::endl;
            std::cout << "add(string(\"hello \"),string(\"world\")) : " << add(string("hello "),string("world")) << std::endl;
            std::cout << "add(string(\"you \"), \"and me\") : " << add(string("you "), "and me") << std::endl; // different type
        }
        
        void test05() {
            using std::vector;
            int target = 22;
            vector<int> vec = { 6,5,6,2,2,3,7,1,9};
            auto ind = std::find_if(vec.begin(), vec.end(), [target](int x) {return x == target;});
            if (ind != vec.end())
                std::cout << "*ind : " << *ind << std::endl; 
            else
                std::cout << "not find" << std::endl;
            std::sort(vec.begin(), vec.end(), [](int a, int b) {return a > b;});
            int cnt = 0;
            std::for_each(vec.begin(), vec.end(), [&cnt](int x) {
                std::cout << cnt + 1 << " : " << x << "     ";
                ++cnt;
            });
            std::cout << std::endl;
        }

        void test06(){
            std::function<int(int)> f;
            f = [](int x) {return x * x;};
            f = [](int x) {return x * 2;};
            f = [](int x) {return x + 3;};
            std::cout << "f(3) : " << f(3) << std::endl;
        }

        void test07(){
            std::vector<int> vec = { 1,2,3,4};
            std::unique_ptr<std::vector<int>> vp = std::make_unique<std::vector<int>>(std::move(vec));
            auto f = [p = std::move(vp)]() {
                std::cout << "for : ";
                for (auto& i : *p) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            };
            f();
            f();
        }
    } // namespace v5
} // namespace test

using namespace test::v5;

int main() {
    test07();

    return 0;
}