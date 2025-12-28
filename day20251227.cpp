// #include <iostream>

// using std::cout;
// using std::endl;

// //全局函数重载+号

// class Person{

// public:
//     int m_A;
//     int m_B;
//     Person(){};
//     Person(int a, int b = 0){
//         m_A = a;
//         m_B = b;
//     }
//     //Person operator+(Person& p);

//     void show();
// };
// // Person Person::operator+(Person &p){
// //     Person temp;
// //     temp.m_A = p.m_A + this->m_A;
// //     temp.m_B = p.m_B + this->m_B;
// //     return temp;
// // }
// void Person::show(){
//     cout << "m_A: " << this->m_A << endl;
//     cout << "m_B: " << this->m_B << endl;
// }
// Person operator+(Person& p1, Person& p2){
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }
// Person operator+(Person &p, int num){
//     Person temp;
//     temp.m_A = p.m_A + num;
//     temp.m_B = p.m_B + num;
//     return temp;
// }
// int main(){
//     Person p1(10,20);
//     Person p2(30,40);

//     Person p3 = p1 + p2;
    
//     Person* p4 = new Person(p2 + p3);

//     p3 = p3 + 10;

//     p3.show();

//     p4->show();


//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Person
// {
//     friend ostream& operator<<(ostream& cout, Person p);
// private:
//     int m_A;
//     int m_B;
//     //通常不使用成员函数左移运算符重载
// public:
//     Person(int a = 0, int b = 0):m_A(a),m_B(b){};

// };
// ostream& operator<<(ostream& cout ,Person p){
//     cout << "m_A = " << p.m_A << endl;
//     cout << "m_B = " << p.m_B << endl;
//     return cout;
// }


// int main(){
//     Person p(10, 20);
//     cout << "----------" << endl << p << "----------" << endl; // <<未重载 error
//     cout << "end" << endl;

//     return 0;
// }

//递增运算符重载

// #include <iostream>

// using namespace std;

// class MyInteger
// {
//     friend ostream& operator<<(ostream& cout, MyInteger myint);
// public:
//     MyInteger()
//     {
//         m_num = 0;
//     }
//     MyInteger(int x)
//     {
//         m_num = x;
//     }
//     MyInteger& operator++()// 返回引用是一直对一个数据进行递增
//     {//前置递增
//         this->m_num += 1;
//         return *this;
//     }
//     MyInteger operator++(int)//前置递增返回的是引用而后置递增返回的是临时值
//     {//这也解释了为什么有时在循环中写前置递增更好 因为不涉及拷贝运算
//         MyInteger temp = *this;
//         this->m_num += 1;
//         return temp;
//     }
//     MyInteger& operator--()
//     {
//         this->m_num -=1;
//         return *this;
//     }
//     MyInteger operator--(int)
//     {
//         MyInteger temp(this->m_num);
//         this->m_num += 1;
//         return temp;
//     }

// private:
//     int m_num;

// };
// //重载<<运算符
// ostream& operator<<(ostream& cout, MyInteger myint){
//     cout << myint.m_num; 
//     return cout;
// }

// int main(){
//     MyInteger myint;

//     // cout << myint << endl;

//     // cout << ++(++myint)<< endl;

//     // cout << myint << endl;

//     //int i = 1;

//     //cout << (i++)++ << endl; //error

//     //cout << ++(++i) << endl;

//     // cout << myint++ <<endl;
//     // cout << myint << endl;

//     // cout << --myint << endl;
//     // cout << --(--myint)<< endl;
//     // cout << myint << endl;
    
//     // cout << myint << endl;
//     // cout << myint-- << endl;
//     // cout << myint <<endl;


//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Person{
// public:
//     Person(int age = 0){
//         m_age = new int(age);
//     }
//     Person(const Person& p){
//         m_age = new int(*p.m_age);
//     }

//     ~Person(){
//         if (m_age != NULL){
//             delete m_age;
//             m_age = NULL;
//         }
//     }

//     Person& operator=(const Person& p){
//         *(m_age) = *(p.m_age);//直接修改值
//         return *this;
//     }

// //private:
//     int* m_age;
// };

// int main(){
//     Person p1(18);

//     //Person p2 = p1;//这是调用了拷贝构造函数实现了p2的初始化

//     Person p2(20);
//     p2 = p1;//这种赋值运算没有调用拷贝构造函数，而上面那一句调用了有参构造函数，
//     //没有发生赋值运算符重载时，上面这一句会导致内存泄漏与同一片内存的重复释放

//     cout << "The age of p1 is " << *p1.m_age << endl;
//     cout << "The age of p2 is " << *p2.m_age << endl;

//     // int a = 10;
//     // int b = 20;
//     // int c = 30;

//     // a = b = c;

//     // cout << "a = " << a << endl;
//     // cout << "b = " << b << endl;
//     // cout << "c = " << c << endl;

//     Person p3(30);
//     Person p4(40);
//     p4 = p3 = p1;

//     cout << "The age of p3 is " << *p3.m_age << endl;
//     cout << "The age of p4 is " << *p4.m_age << endl;

//     return 0;
// }

//关系运算符重载

// #include <iostream>

// using namespace std;

// class Person
// {
// public:

//     Person(string name, int age)
//     {
//         m_name = name;
//         m_age = age;
//     }

//     bool operator==(Person& p){
//         if (this->m_age == p.m_age && this->m_name == p.m_name)
//             return true;
//         else
//             return false;
//     }

//     string m_name;
//     int m_age;
// };

// int main()
// {
//     Person p1("Tom",18);

//     Person p2("Tom",18);

//     if (p1 == p2){
//         cout << "p1和p2是相等的" << endl;
//     }
//     return 0;
// }

//函数调用运算符重载

//仿函数非常灵活 重载()

// #include <iostream>

// using namespace std;

// class MyPrint
// {
// public:
//     //重载函数调用运算符
//     void operator()(string test)
//     {
//         cout << test << endl;
//     }
// };
// class MyAdd
// {
// public:
//     int operator()(int x, int y){
//         return x + y;
//     }
// };
// int main(){
//     MyPrint print;
//     print("helloworld");//使用起来非常像函数 因此称为仿函数

//     MyAdd add;
//     cout << add(1,2) << endl;

//     //匿名函数对象
//     cout << MyAdd()(100,200) << endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Java
// {
// public:
//     void header()
//     {
//         cout << "首页 公开课 登录 注册" << endl;
//     }
//     void footer()
//     {
//         cout <<"帮助中心 交流合作 站内地图" << endl;
//     }
//     void left()
//     {
//         cout << "Java python C++"<< endl;
//     }
//     void content()
//     {
//         cout << "Java学科视频" <<endl;
//     }
// };
// class Python
// {
// public:
//     void header()
//     {
//         cout << "首页 公开课 登录 注册" << endl;
//     }
//     void footer()
//     {
//         cout <<"帮助中心 交流合作 站内地图" << endl;
//     }
//     void left()
//     {
//         cout << "Java python C++"<< endl;
//     }
//     void content()
//     {
//         cout << "Python学科视频" <<endl;
//     }
// };
// class Cpp
// {
// public:
//     void header()
//     {
//         cout << "首页 公开课 登录 注册" << endl;
//     }
//     void footer()
//     {
//         cout <<"帮助中心 交流合作 站内地图" << endl;
//     }
//     void left()
//     {
//         cout << "Java python C++"<< endl;
//     }
//     void content()
//     {
//         cout << "c++学科视频" <<endl;
//     }
// };
// void test1()
// {
//     cout << "Java下载视频页面如下：" << endl;
//     Java ja;
//     ja.header();
//     ja.left();
//     ja.content();
//     ja.footer();
//     cout << "------------------------------"<<endl;
//     cout << "python下载视频页面如下：" << endl;
//     Python py;
//     py.header();
//     py.left();
//     py.content();
//     py.footer();
//     cout << "------------------------------"<<endl;
//     cout << "c++下载视频页面如下：" << endl;
//     Cpp cpp;
//     cpp.header();
//     cpp.left();
//     cpp.content();
//     cpp.footer();
// }
// #include <iostream>
// using namespace std;

// class BasePage
// {
// public:
//     void header()
//     {
//         cout << "首页 公开课 登录 注册" << endl;
//     }
//     void footer()
//     {
//         cout <<"帮助中心 交流合作 站内地图" << endl;
//     }
//     void left()
//     {
//         cout << "Java python c++" << endl;
//     }
// };
// class Java: public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Java学科视频" << endl;
//     }
// };
// class Python:public BasePage
// {
// public:
//     void content()
//     {
//         cout <<"Python学科视频" << endl;
//     }
// };
// class print
// {
// public:
    
// };
// class Cpp:public BasePage 
// {
// public:
//     void content()
//     {
//         cout << "c++学科视频" << endl;
//     }
// };
// void test2()
// {
//     cout << "Java下载视频页面如下：" << endl;
//     Java ja;
//     ja.header();
//     ja.left();
//     ja.content();
//     ja.footer();
//     cout << "------------------------------"<<endl;
//     cout << "python下载视频页面如下：" << endl;
//     Python py;
//     py.header();
//     py.left();
//     py.content();
//     py.footer();
//     cout << "------------------------------"<<endl;
//     cout << "c++下载视频页面如下：" << endl;
//     Cpp cpp;
//     cpp.header();
//     cpp.left();
//     cpp.content();
//     cpp.footer();
// }

// int main(){

//     test2();

//     return 0;
// }

//不同继承方式

// #include <iostream>
// using namespace std;

// class Base1
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C;
// };
// class Son1:public Base1
// {
// public:
//     void func()
//     {
//         m_A = 10;
//         m_B = 10;
//         //m_C = 10; //error无法访问
//     }
// };
// class Son2:protected Base1
// {
// public:
//     void func()
//     {
//         m_A = 10;
//         m_B = 20;
//         //m_C = 30;//无法访问
//     }
// };
// class Son3:private Base1
// {
// public:
//     void func()
//     {
//         m_A = 10;
//         m_B = 20;
//         //m_C = 30;//无法访问
//     }
// };
// class Grandson3:public Son3
// {
// public:
//     void func()
//     {
//         // m_A = 10; // 私有成员无论何种继承均无法访问
//         // m_B = 20;

//     }
// };

// int main(){
//     Son1 s1;
//     s1.m_A = 1;
//     //S1.m_B = 2;//保护权限无法访问

//     Son2 s2;
//     //s2.m_A = 20;//保护权限无法访问

//     Son3 s3;
//     //s3.m_A = 10;//私有权限无法访问
//     //s3.m_B = 10;//error

//     return 0;
// }
#include <iostream>

using namespace std;
class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
public:
    Base()
    {
        cout << "Base 构造函数调用" << endl;
    }
    ~Base()
    {
        cout << "Base 析构函数调用" << endl;
    }
};
class Son: public Base 
{
public:
    Son()
    {
        cout << "Son 构造函数调用" << endl;
    }
    ~Son()
    {
        cout << "Son 析构函数调用" << endl;
    }
    int m_D;
};

int main()
{
    //cout << "sizeof Son is " << sizeof(Son) << endl;
    //父类中的所有非静态属性都会被子类继承下去
    //弗雷中私有成员属性是被编译器给隐藏了，因此是访问不到

    // {
    //     Base b;
    // }
    {
        Son s;
    }


    return 0;
}