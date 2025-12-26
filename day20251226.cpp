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

//c++ python化
class Person
{
public:

};

int main(){

    return 0;
}