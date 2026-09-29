#include <iostream>
#include <unistd.h>
#include <string.h>

void test01() {
    std::cout << "hello world" << std::endl;
    if (0 == fork())
        std::cout << "child : hello world" << std::endl;
    else
        std::cout << "parent : hello world" << std::endl;

}

int main() {

    return 0;
}