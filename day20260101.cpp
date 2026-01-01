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


#include <iostream>

using namespace std;

class Animal
{
public:
    int m_age;
};
class Sheep:virtual public Animal
{
public:
};
class Camel:virtual public Animal
{
public:
};
class Alpaca:public Sheep,public Camel
{

};
//vbptr virtual basic pointer虚基类指针


int main(){
    Alpaca a;
    a.Sheep::m_age = 10;
    a.Camel::m_age = 20;

    cout << a.Sheep::m_age << endl;
    cout << a.Camel::m_age << endl; 

    cout << sizeof a << endl;




    return 0;
}