#include <iostream>
#include <thread>
namespace test {
    template <typename Callable>
    class Task {
    public:
        Task(Callable call) : call_(call){

        }
        template <typename... Args>
        decltype(std::declval<Callable>()(std::declval<Args>()...)) operator()(Args&&... args) {
            return call_(std::forward<Args>(args)...);
        }
    private:
        Callable call_;
    };
    void test01() {
        Task t{[](std::size_t times){
            for (std::size_t i = 0; i < times; ++i) {
                std::cout << "hello world" << std::endl;
            }
        }};
        std::thread thread(t ,3);
        thread.join();
    }
}

int main() {
    test::test01();



    return 0;
}