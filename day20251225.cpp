#include <iostream>

using namespace std;

class a{

};

struct b{

};

int main(){
    //成员变量和成员函数分开存储
    cout << sizeof (a) << endl;
    cout << sizeof (b) << endl;

    return 0;
}

