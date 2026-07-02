#include <iostream>

int main() {
    // 定义常量 kCount，表示循环次数
    constexpr int kCount = 100;
    // 定义常量 kMessage，表示要输出的字符串
    constexpr const char* kMessage = "Hello world";
    // 循环 kCount 次，每次输出 kMessage
    for (int i = 0; i < kCount; ++i) {
        std::cout << kMessage << '\n';
    }

    return 0;
}
