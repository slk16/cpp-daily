// #include <iostream>

// using namespace std;

// class Base{
// public:
//     int m_a;
//     int m_b;
//     Base(){
//         m_b = 100;
//     }
//     void print(){
//         cout << "Base print" << endl;
//     }

// };
// class Son:public Base
// {
// public:
//     Son(){
//         m_b = 200;
//     }
//     void print(){
//         cout << "Son print" << endl;
//     }
//     void print(int){
//         cout << "Son print int" << endl;
//     }
//     int m_b;
//     int m_c;
// };
// class Grandson:public Son
// {
// public:
//     Grandson(){
//         m_b = 300;
//     }
//     void print(){
//         cout << "Grandson print" << endl;
//     }
//     int m_b;
// };


// int main(){
//     // Son s;
//     // cout << s.Base::m_b << endl;

//     // s.Base::print();

//     // Grandson gs;

//     // cout << gs.Base::Son::m_b << endl;

//     Grandson gs;

//     // gs.print(10);//子类中的同名成员会隐藏掉父类中的同名成员

//     gs.Son::print(10);


//     return 0;
// }


//继承同名静态成员处理方式
#include <iostream>

using std::cout;

using std::endl;

class Base{
public:
    static void func(){
        cout << "Base func() call" << endl;
    }
    static int m_a;
};
int Base::m_a = 1;


class Son: public Base{
public:
    static void func(){
        cout << "Son func() call" << endl;
    }
    static int m_a;//静态成员函数位于静态区 必须要进行初始化
};
int Son::m_a = 2;

int main(){
    Son s;
    s.Base::func();
    cout << s.m_a << endl;
    cout << s.Base::m_a<< endl;

    s.m_a = 100;

    cout << s.m_a << endl;



    return 0;
}

