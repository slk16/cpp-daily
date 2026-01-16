#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//int main(){
//    fstream fs;
//
//    fs.open("C:Users\\pc\\Desktop\\test.txt", ios::in);
//    if (fs.is_open() == true){
//        cout << "打开成功" << endl;
//    }
//    else
//    {
//        cout << "打开失败" << endl;
//    }
    //方法一
//    char buffer[1024] = { 0 };
//    while (fs >> buffer){
//        cout << buffer << endl;
//    }
        
    //方法二
//    char buffer[1024]= { 0 };
//    while ( fs.getline(buffer, sizeof(buffer))){
//        cout << buffer << endl;
//    }
    
    //方法三
//    string buf;
//    while (getline(fs,buf)){
//        cout << buf << endl;
//    }

    //方法四
//    char c;
//    while ( (c = fs.get()) != EOF){
//        cout << c;
//    }
//
//     
//
//    fs.close();
//    return 0;
//}
//class Person
//{
//public:
//    
//    char m_Name[64];
//    int m_Age;
//
//};
//
//int main(){
//    //ofstream& write(const char * buffer, int len)
//    ofstream ofs;
//
//    ofs.open("C:\\Users\\pc\\Desktop\\test.txt", ios::binary | ios::out);
//    char buffer[1024] = { 0 };
//    Person p = {"zhangsan", 64};
//
//    ofs.write((const char*)&p, sizeof(Person));
//    ofs.close();
//
//    ifstream ifs;
//    
//    ifs.open("C:\\Users\\pc\\Desktop\\test.txt", ios::binary | ios::in);
//    if (ifs.is_open() == false)
//    {
//        cout << "File opened fail" << endl;
//    }
//
//    Person p2;
//    ifs.read((char*)&p2,sizeof(Person));
//
//    cout << "name: " << p2.m_Name << endl;
//
//    cout << "age:  " << p2.m_Age << endl;
//    ifs.close();
//
//    return 0;
//}
