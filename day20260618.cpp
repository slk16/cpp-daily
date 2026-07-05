#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::vector<int> ivec;

    for (int i = 0; i < 10; ++i) {
        [ivec]() mutable -> void{
            int x;
            std::cin >> x;
            ivec.push_back(x);
        }
    }

    return 0;
}