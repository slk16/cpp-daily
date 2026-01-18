//#include <iostream>
//
//using namespace std;
//
//class Base
//{
//public:
//    int a;
//    Base();
//    virtual ~Base();
//};
//class Derived: public Base
//{
//public:
//    int b;
//    Derived();
//    virtual ~Derived();
//};
//Derived::Derived()
//{
//    cout << "Derived constructor call" << endl;
//}
//Derived::~Derived()
//{
//    cout << "Derived deconstructor call" << endl;
//}
//Base::Base()
//{
//    cout << "Base constructor call" << endl;
//}
//Base::~Base()
//{
//    cout << "Base deconstructor call" << endl;
//}
//
//int main()
//{
//    //string str;
//    //cin >> str;
//    //if (str == "a")
//    //{
//        //cout << "str == \"a\"" << endl;
//    //}
//    Base* b = new Derived;
//    cout << "test1" << endl;
//    delete b;
//
//    return 0;
//}
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func()const{
        cout << "Base func() call" << endl;
    }
    int m_a;
};
class Derived:public Base
{
private:
    // 如果基类成员函数为常函数 则派生类成员进行重写时也要声明为常函数否则不能进行重写
    //virtual void func()override // error
    virtual void func()const override{
        cout << "Derived func() call" << endl;
    }
    int m_b;
};

int add1(int a, int b)
{
    return a + b;
}
template<class T>
T add(T a, T b)
{
    return a + b;
}
void test01()
{
    //int ret = add1(10,20);
    //cout << ret << endl; 

    //发生了隐式类型转换
    cout << add1(10,'a') << endl;

    int a = 10,b = 20;
    char c = 'c';
    //int ret = add(a,c);//error
    // 注意T& a引用类型本质是常量指针 无法进行隐式类型转换
    int ret = add<int>(a,c);
    cout << ret << endl; 
}
void print(const Base& b)
{
    b.func();
}

int main()
{
//    test01();

    Base b;
    Derived d;

    print(b);
    print(d);
    
    return 0;
}