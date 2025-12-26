#include <iostream>

using namespace std;

// class P{
//     int a;//非静态成员变量属于类

//     static int b;//静态成员变量不属于类

//     void func(){//非静态成员函数不属于类

//     }
//     static void func2(){//静态成员函数也不属于类

//     }
// };

// class Person{
// public:
//     Person(int age)
//     {
//         this->age = age;// this指针指向被调用的成员函数所属的对象
//         //this 指针可以绕过权限
//     }
//     int getAge(void){
//         return age;
//     }
// private:
//     int age;
// };

// int main(){
//     //成员变量和成员函数分开存储 
//     //cout << "sizeof P is " << sizeof(P) << endl;
//     Person p1(18);
//     //Person p2(20);
//     //Person* pp2 = &p2;
//     //pp2->age;
//     //cout << "p1的年龄是： "<< p1.getAge() << endl;

//     return 0;
// }

// class Person{
// public:
//     Person(int age)
//     {
//         this->age = age;
//     }

//     Person& PersonAddAge(Person &p)
//     {
//         this->age += p.age;
//         return *this;
//     }

//     int age;
// };
// int main(){
//     Person p1(10);

//     Person p2(10);

//     p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

//     cout << "The age of p2 is " << p2.age<< endl;
//     //链式编程思想

//     return 0;
// }

//空指针访问成员函数

// class Person
// {
// public:
//     void showClassName()
//     {
//         cout << "This is Person class"<<endl;
//     }

//     void showPersonAge()
//     {
//         if (this == NULL) return;// 防止代码崩溃 提高代码鲁棒性

//         cout << "age = " << m_age << endl;// 这个非静态成员函数的m_age前默认有一个this指针 传入指针为空导致报错
//     }

//     int m_age;
// };

// int main(){

//     Person *p = NULL;

//     p->showClassName();// 此句代码不报错
    
//     p->showPersonAge();


//     return 0;
// }
 



// class Person
// {
// public:
//     // void setA() const//这个const相当于修饰了this 即为 const Person* const this
//     // {
//     //     // m_C = 200;
//     //     //m_A = 100; // 不可修改,如果没有const 可以通过this去访问

//     //     m_B = 100;
//     //     //
//     //     //this = NULL; // this 是指针常量不可修改
//     // }
//     // void setB()
//     // {
//     //     m_A = 20;
//     // }
//     // void show()
//     // {
//     //     cout << "m_A = " << m_A << endl;
//     //     cout << "m_B = " << m_B << endl;
//     //     // cout << "m_C = " << m_C << endl;

//     // }

//     int m_A;
//     mutable int m_B;
//     // static int m_C;
// };
// //int Person:: m_C = 0;

// int main(){
//     // Person p1;
//     // p1.setA();
//     // p1.setB();
//     // p1.show();

//     //常对象

//     //const Person p;
//     //p2.m_A = 30; // error
//     // p2.m_B = 30;
//     // p2.m_C = 40;
 



//     return 0;
// }

// class Person{

// public:
//     int m_A;


// };

// int main(){
//     int x{10};
    
//     cout <<"The value of x is " << x << endl;

//     return 0;
// }

// class Person{
// public:
//     Person(){
//         m_A = 0;
//     }
//     int m_A;
//     void func1() const{
//         cout << "调用const void func1() " << endl;;
//     }
//     void func2(){
//         ;
//     }
// };

// int main(){
//     const Person p;
//     p.func1();
//     //p.func2();

//     return 0;
// }

