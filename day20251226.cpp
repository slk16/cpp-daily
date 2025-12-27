#include <iostream>

using namespace std;

// class Building
// {
//     friend void goodGuy(Building* building);//goodGuy全局函数是building好朋友 可以访问私有成员
//     // 这句代码只要写在类中就可以
// public:
//     Building()
//     {
//         m_SittingRoom = "客厅";
//         m_BedRoom = "卧室";
//     }


// public:
//     string m_SittingRoom;
// private:
//     string m_BedRoom;
// };
// void goodGuy(Building* building){

//     cout << "正在访问: " << building->m_SittingRoom << endl;

//     // cout << "正在访问: " << building->m_BedRoom << endl; // error 无法访问

    

// }

// int main(){
//     Building b;
//     goodGuy(&b);


//     return 0;
// }
// class Building;
// class Goodguy
// {
// public:
//     Building* building;
//     Goodguy();
//     void visit();
// };
// class Building
// {
//     friend class Goodguy;
// public:
//     string m_SittingRoom;//
//     Building();
// private:
//     string m_BedRoom;

// };
// Building::Building()
// {
//     m_SittingRoom = "客厅";
//     m_BedRoom = "卧室";
// }
// Goodguy::Goodguy()
// {
//     building = new Building;
// }
// void Goodguy::visit(){
//     cout << "好基友正在访问： " << building->m_SittingRoom << endl;

//     cout << "好基友正在访问： " << building->m_BedRoom << endl;
// }
// int main(){
//     Goodguy gg;
//     gg.visit();

//     return 0;
// }

// class Building;
// class GoodGuy
// {

// public:
//     GoodGuy();

//     void visit1();//不做友元
//     void visit2();//做友元

//     Building* building;
// };
// class Building{
//     friend void GoodGuy::visit2();
// public:
//     Building();

// public: 
//     string m_SettingRoom; 
// private:
//     string m_BedRoom;

// };
// //building实现
// Building::Building(){
//     m_SettingRoom = "客厅";
//     m_BedRoom = "卧室";
// }
// //building
// //----------------
// //Goodguy实现
// GoodGuy::GoodGuy(){
//      building = new Building;
// }
// void GoodGuy::visit1(){
//     cout << "visit1正在访问: " << building->m_SettingRoom << endl;

//     // cout << "visit1正在访问: " << building->m_BedRoom << endl; // error 
// }
// void GoodGuy::visit2(){
//     cout << "visit2正在访问: " << building->m_SettingRoom << endl;
    
//     cout << "visit2正在访问: " << building->m_BedRoom << endl; // 不报错友元成员函数构造成功
    
// }

// int main(){
 
//     GoodGuy gg;
//     gg.visit1();
//     gg.visit2();

//     return 0;
// }

//运算符重载

//c++ python化 :P
class Person
{
public:
    int m_A;
    int m_B;

    Person operator+(const Person& p)
    {
        Person temp;
        temp.m_A = p.m_A + this->m_A;
        temp.m_B = p.m_B + this->m_B;
        return temp;//  值返回
    }
    void show(){
        cout << "m_A: " << this->m_A << '\t';
        cout << "m_B: " << this->m_B << endl;
    }
    Person(){};

    Person(int a, int b = 0):m_A(a),m_B(b){};

    ~Person(){};
    //Person Person::PersonAddPerson(Person& p);// 类内声明
};
// Person Person::PersonAddPerson(Person& p)
// {
//     Person temp;
//     temp.m_A = p.m_A + this->m_A;
//     temp.m_B = p.m_B + this->m_B;
//     return temp;//  值返回
// }//类外定义

int main(){
    Person p1(1,2);
    Person p2(2,3);
    Person p3 = p1 + p2;
    p3.show();

    return 0;
}





