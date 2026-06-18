#include <iostream>
struct stu{
    int year, month, day;
}stu;

int main() {
    std::cout << sizeof(struct stu) << std::endl;

    return 0;
}