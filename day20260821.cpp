#include <iostream>
#include <thread>
namespace test {
    template <typename... Args> inline
    std::thread make_thread(Args&&... args) {
        std::thread ret{ std::forward<Args>(args)... };
        return ret;
    }
    void test01() {
        std::thread a = make_thread([]() {
            std::cout << "hello world" << std::endl;
        });
        a.join();
    }
    namespace test_name {
        class base {
        public:
            int x = 0;
            int z = 30;
        };
        class derived : public base {
        public:
            int x = 10;
            int y = 20;
        };
        void test01() {
            derived a;
            std::cout << a.x << std::endl;
            std::cout << a.y << std::endl;
            std::cout << a.z << std::endl;
        }
    }
    namespace test_virtual {
        class base {
            void operator+(){
                std::cout << "+";
            }
            void operator()() {
                std::cout << "base" << std::endl;
            }
        };
        class derived  : public base{
            void operator()(){
                std::cout << "derived" << std::endl;
            }
        };
        void test01() {
        }
    }
    void test02(int argc, char* argv[], char* envp[]) {
        std::cout << "argc : " << argc << std::endl;
        int i = 0;
        while (argv[i] != 0) {
            std::cout << argv[i] << " ";
            ++i;
        }
        std::cout << std::endl;
        i = 0;
        std::cout << "env : " << std::endl;
        while (envp[i]!=0) {
            std::cout << envp[i] << " ";
            ++i;
        } 
        std::cout << std::endl;
    }

} // namespace test


int main(int argc, char* argv[], char* envp[]) {
    test::test02(argc, argv, envp);
    test::test01();
    //test::test_name::test01();


    return 0;
}