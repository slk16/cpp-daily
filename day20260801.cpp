#include <iostream>
namespace test{
    namespace t1{
        void test01() {
            long a = 0x1234567811223344;
            int* p = (int*)&a;
            *p = 3;
            for (int i = 63; i >= 0; --i) {
                std::cout << ((a >> i) & 1);
                if ((i & 3l) == 0)
                    std::cout << " ";        
            }
            std::cout << '\n';
        }
    }
    namespace t2 {

        
    }

}

int main() {
    long local;
    std::cout << &local << std::endl;

    return 0;
}