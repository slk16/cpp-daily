#include <iostream>
void f(int*) {

}
template <typename T>
void g(T, T) {
    
}
void test01() {
    auto a = &f;
    //auto b = &g;
    void (*p)(char, char) = &g;
}

int main() {
    test01();
    
}