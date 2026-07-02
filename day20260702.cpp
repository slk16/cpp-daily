#include <iostream>

int main() {
    constexpr int kCount = 100;
    constexpr const char* kMessage = "Hello world";
    for (int i = 0; i < kCount; ++i) {
        std::cout << kMessage << '\n';
    }

    return 0;
}
