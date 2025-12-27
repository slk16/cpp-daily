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

#include <iostream>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream& cout, Person p);
private:
    int m_A;
    int m_B;
    //通常不使用成员函数左移运算符重载
public:
    Person(int a = 0, int b = 0):m_A(a),m_B(b){};

};
ostream& operator<<(ostream& cout ,Person p){
    cout << "m_A = " << p.m_A << endl;
    cout << "m_B = " << p.m_B << endl;
    return cout;
}


int main(){
    Person p(10, 20);
    cout << "----------" << endl << p << "----------" << endl; // <<未重载 error
    cout << "end" << endl;

    return 0;
}