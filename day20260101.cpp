#include <iostream>

using namespace std;

// void print(char a){
//     for (int i = 7;i >= 0;i--){
//         cout << ((a>>i)&1);
//     }
// }

// int main()
// {
//     for (int i =0;i < 256;i++){
//         print((char)i);
//         cout << endl;
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;


// class int_b{
//     friend ostream& operator<<(ostream& cout, int_b integer);
//     friend int_b operator+(int_b& b);
// private:
//     int m_a;
// public:
//     int_b(){};
//     int_b(int a){
//         m_a = a;
//     }
//     int_b& operator=(int a){
//         m_a = a;
//         return *this;
//     }
//     int_b operator+(int_b& b){
//         int_b temp = this->m_a + b.m_a;
//         return temp;
//     }
// };
// ostream& operator<<(ostream& cout, int_b integer){
//     for(int i = 31; i >= 0;i--){
//         cout <<((integer.m_a>>i)&1);
//         if(i%4==0){
//             cout << ' ';
//         }
//     }
//     return cout;
// }

// int main(){
//     int_b a = 17;
//     cout << a << endl;

//     int_b b;
//     b = a = 20;
//     cout << a << endl;
//     cout << b << endl;

//     b = a + b;

//     cout << b << endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Base{
// public:
//     static void func(){
//         cout << "Base调用" << endl;
//     }
//     static void func(int ){
//         cout << "Base调用int" << endl;
//     }

//     static int m_a;
// };
// int Base::m_a = 1;

// class Son:public Base
// {
// public:
//     static void func(){
//         cout << "Son调用"<<endl;
//     }

//     static int m_a;
// };
// int Son::m_a = 2;





// int main(){
//     // Son s;
//     // cout << s.m_a << endl;
//     // cout << s.Base::m_a << endl;

//     // cout << Base::m_a << endl;
//     // cout << Son::Base::m_a << endl;
//     // cout << Son::m_a << endl;

//     // Son S;
//     // S.func();
//     // S.Base::func();
//     // Base::func();
//     // Son::func();
//     // Son::Base::func();

    

//     return 0;
// }

// #include <istream>
// using namespace std;

// class Base1
// {
// public:
//     int m_a;
//     Base1(){
//         m_a = 100;
//     }
// };
// class Base2
// {
// public:
//     int m_a;
//     Base2(){
//         m_a = 200;
//     }
// };

// class Son:public Base1 ,public Base2
// {
// public:
//     Son(){
//         m_b = 300;
//         m_c = 400;
        
//     }
//     int m_b;
//     int m_c;
// };



// int main()
// {
//     cout << sizeof (Son) << endl;

//     Son s;

//     cout << s.Base1::m_a << endl;
//     cout << s.Base2::m_a << endl;


//     return 0;
// }


// #include <iostream>

// using namespace std;

// class Animal
// {
// public:
//     int m_age;
// };
// class Sheep:virtual public Animal
// {
// public:
// };
// class Camel:virtual public Animal
// {
// public:
// };
// class Alpaca:public Sheep,public Camel
// {

// };
// //vbptr virtual basic pointer虚基类指针
// //指向虚基类表 vbtable


// int main(){
//     Alpaca a;
//     a.Sheep::m_age = 10;
//     a.Camel::m_age = 20;

//     cout << a.Sheep::m_age << endl;
//     cout << a.Camel::m_age << endl; 

//     cout << sizeof a << endl;

//     return 0;
// }

// class Animal
// {
// public:
//     virtual void speak()//虚函数
//     {
//         cout << "动物在说话" << endl;
//     }
// };
// // class base
// // {
// // public:
// //     int m_a;
// // };
// class Cat: public Animal
// {
// public:
//     void speak()
//     {
//         cout << "小猫在说话" << endl;
//     }
// };
// class Dog: public Animal
// {
// public:
//     void speak() 
//     {
//         cout <<"小狗在说话"<<endl;
//     }
// };
// void doSpeak(Animal& animal)//地址早绑定
// {// 父类指针或引用指向子类对象

            
//     animal.speak();
// }


// int main()
// {
//     Cat cat;
//     doSpeak(cat);
//     Dog dog;
//     doSpeak(dog);

//     Animal* a = new Animal;
//     a->speak();


//     return 0;   
// }

// class Base
// {
// public:
//     virtual void show(){
//         cout << "Base" <<endl;
//     }
//     int m_a;
//     Base(){
//         m_a = 1;
//     }
// };
// class Son1:public Base
// {
// public:
//     void show(){
//         cout <<"Son1"<<endl;
//     }
//     int m_b;
//     Son1(){
//         m_b = 2;
//     }
// };
// class Son2:public Base
// {
// public:
//     void show(){
//         cout <<"Son2"<<endl;
//     }
// };
// void doShow(Base& b){
//     b.show();
// }
// int main(){
//     Base* a;
//     Son1 b;
//     Son2 c;
//     a = &b;
//     a->show();

//     doShow(c);

//     return 0;
// }

//接下来简单了解一下c++模版是什么 基本语法是什么

// template<typename T>
// void func(T a){
//     cout << a << endl;
// }


// int main(){
//     func<int>(1);//自动类型推导
//     func("helloworld");
//     func(2.2);

//     func<const char*>("hello template");

//     return 0;
// }



