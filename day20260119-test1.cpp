//#include <iostream>
//#include <string>

//using namespace std;

//template<class T>
//void Swap(T& a,T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//int main()
//{
//    int a = 10, b = 20;
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    Swap<int>(a,b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//
//
//    return 0;
//}

//函数模板
//void myPrint(int a, int b)
//{
//    cout << "调用的普通函数" << endl;
//}

//template<class T>
//void myPrint(T a, T b)
//{
//    cout << "调用函数模板" << endl;
//}
//template<class T>
//void myPrint(T a, T b,T c)
//{
//    cout << "调用重载函数模版" << endl;
//}

//int main()
//{
//    int a = 10;
//    int b = 20;
//    int c = 30;
//    //myPrint(a,b);
//    //myPrint<>(a,b);
//    //myPrint(a,b,c);

//    char c1 = 'a';
//    char c2 = 'b';

//    myPrint(c1,c2);// 函数模版发生了更好的匹配

//    return 0;
//}

//模版具备局限性

//可以对特定数据类型做出特殊实现

//class Person
//{
//public:
//    string m_name;
//    int m_age;
//    Person(string name,int age = 0)
//    {
//        m_name = name;
//        m_age = age;
//    }
//    bool operator==(const Person& p)
//    {
//        if (p.m_name == this->m_name && p.m_age == this->m_age)
//            return true;
//        else
//            return false;
//    }
//};
//template<class T>
//bool compare(T& a, T& b)
//{
//    if (a == b)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//template<> bool compare(Person& a,Person& b)
//{
//    if (a.m_name == b.m_name && a.m_age == b.m_age)
//        return true;
//    else
//        return false;
//}
//void test01()
//{
//    int a = 10;
//    int b = 20;
//    int ret = compare(a,b);
//    if (ret)
//    {
//        cout << "True" << endl;
//    }
//    else
//    {
//        cout << "False" << endl;
//    }
//}
//void test02()
//{
//    Person p1("Tom",10);
//    Person p2("Tom",10);
//    if (compare(p1,p2))
//    {
//        cout << "True" << endl;
//    }
//    else
//    {
//        cout << "False" << endl;
//    }
//}
//
//int main()
//{
//    test02();
//
//
//    return 0;
//}
//template<class T >
//void print(T& a)
//{
//    cout << a << endl; 
//}
//
//template<class NameType,typename AgeType = int>
//class Person
//{
//public:
//    NameType m_Name;
//    AgeType m_Age;
//
//    Person(NameType name, AgeType age)
//    {
//        m_Name = name;
//        m_Age = age;
//    }
//    void showInfo()
//    {
//        cout << "name: " << m_Name << endl;
//        cout << "age:  " << (int)m_Age << endl;
//    }
//};
//int main()
//{
//    Person <string,unsigned char>p1("zhangsan",18);
//    p1.showInfo();
//
//    //int a = 10;
//    //print(a);
//    //char c = 'c';
//    //print(c);
//
//    return 0;
//}

//class Person1
//{
//public:
//    void showPerson1()
//    {
//        cout << "show Person1" << endl;
//    }
//};
//class Person2
//{
//public:
//    void showPerson2()
//    {
//        cout << "show Person2" << endl;
//    }
//};
//template<typename T>
//class Base
//{
//public:
//    T obj;
//    void func1()
//    {
//        obj.showPerson1(); 
//    }
//    void func2()
//    {
//        obj.showPerson2();
//    }
//    
//};
//int main()
//{
//    Base<Person1> b;
//    b.func1();
//    //b.func2();
//
//
//    return 0;
//}

//1、指定传入类型
//2、参数模版化
//3、整个类作为模版

//template<typename NameType,typename AgeType>
//class Person
//{
//public:
//    Person(NameType name,AgeType age)
//    {
//        m_Name = name;
//        m_Age = age;
//    }
//    NameType m_Name;
//    AgeType m_Age;
//
//    void showPerson()
//    {
//        cout << "name: " << m_Name << endl
//        << "age: " << m_Age << endl;
//    }
//};
//1、显示指定类型
//void showPerson(Person<string,int>p)
//{
//    p.showPerson();
//}
//2、参数模版化
//template<class T1,class T2>
//void showPerson(Person<T1,T2> p)
//{
//    p.showPerson();
//    cout << "T1 Type: " << typeid(T1).name() << endl;
//    cout << "T2 Type: " << typeid(T2).name() << endl;
//}
////3、整个类模版化o
//template<class T>
//void showPerson(T& p)
//{
//    p.showPerson();
//    p.cout << "Type: " << typeid(p).name() << endl;
//}
//
//int main()
//{
//    Person<string,int> p("zhangsan",18);
//    showPerson(p);
//
//    return 0;
//}

//template <class T>
//class Base
//{
//public:
//    T a;
//};
//class Derived: public Base<int>
//{
//private:
//    int b;
//};
//template <class T1,class T2>
//
//class Derived2: public Base<T1>
//{
//public:
//    Derived2()
//    {
//        cout << "T1 Type: " << typeid(T1).name() << endl;
//        cout << "T2 Typ2: " << typeid(T2).name() << endl;
//    }
//    int a;
//    T2 c;
//};
//int main()
//{
//    Derived2<string,int> d;
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
////类模板成员的类外实现
//template <class a,class b>
//class Person;
//
//int add(int a,int b);
//
//
//void test01()
//{
//    //Person<string,int> p("lisi", 22);// 错误
//    //p.showInfo();
//
//    int a = 12,b = -2;
//    cout << "The result: " << add(a,b);
//}
//int add(int num1,int num2)
//{
//    if (!num1) {return num2;}
//    return add((num1 & num2) << 1,num1 ^ num2);
//}
//class Base
//{
//public:
//    void show()
//    {
//        cout << "hello" << endl; 
//    }
//    void showhello()
//    {
//        cout << "showhello" << endl; 
//    }
//};
//template<class T1,class T2>
//class Person
//{
//public:
////    Person(string name, int age){
////        m_Name = name;
////        m_Age = age;
////    }
//    //Person(){};
//    Person(T1 m_Name,T2 m_Age);
//
//    void print(Base T3)
//    {
//        T3.showhello();
//    }
//
//
//    void showInfo();
//    T1 m_Name;
//    T2 m_Age;
//}; 
//template <class T1,class T2>
//Person<T1,T2>::Person(T1 name,T2 age)
//{
//    m_Name = name;
//    m_Age = age;
//}
//
//
//template<class T1,class T2>
//void Person<T1,T2>::showInfo()
//{
//    cout << "Name: " << m_Name << endl;
//    cout << "Age:  " << m_Age << endl;
//}
//
//int main()
//{
//    //Base t;
//    //Person<string,int> p("zhangsan",18);
//    //p.showInfo(); 
//    //p.print(t);
//    test01();
//
//    return 0;
//}

//类模板进行份文件编写
//类模板中的成员函数只有在调用时才进行检查，所以要通过特殊方式进行编写

//#include "D:\\cpp-code\\headfile\\day20260119.h"

//int main()
//{
    //a a1;
    //a1.print();

    //return 0;
//}
