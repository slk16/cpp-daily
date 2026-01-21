//#include <iostream>
//using namespace std;
//
////void show();//类内实现的全局函数如果没有参数
//template<class T1,class T2>
//class Person;
//
//template<class T1,class T2>
//void showPerson(Person<T1,T2>& p)
//{
//    cout << "Name: " << p.m_Name << endl
//    << "Age:  " << p.m_Age << endl;
//}
//
//template<class T1,class T2>
//class Person
//{
//    //template<class t1,class t2>
//    friend void showPerson<>(Person<T1,T2>& p);
//
//    friend void show()
//    {
//        cout << "Person show" << endl;
//    }
//private:
//    T1 m_Name;
//    T2 m_Age;
//public:
//    void showInfo();
//    Person(T1 name,T2 age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }
//};
//
//template<class T1,class T2>
//void Person<T1,T2>::showInfo()
//{
//    cout << "Name: " << m_Name << endl
//    << "Age:  " << m_Age << endl;
//}
//
//int main()
//{
//    Person<string,int> p("zhangsan",18);
//    p.showInfo();
//    cout << "-------------" << endl;
//    showPerson(p);
//    cout << "-------------" << endl;
//
//    return 0;
//}

//实现一个通用的数组类

