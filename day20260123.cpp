#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

int main()
{
//    vector<Person> v;
//    Person p1("aaa",10);
//    Person p2("bbb",20);
//    Person p3("ccc",30);
//    Person p4("ddd",40);
//    Person p5("eee",50);
//
//    v.push_back(p1);
//    v.push_back(p2);
//    v.push_back(p3);
//    v.push_back(p4);
//    v.push_back(p5);
//
//    for (vector<Person>::iterator it = v.begin();it != v.end();it++)
//    {
//        cout << "Name:  " << (*it).m_Name << endl; 
//        cout << "Age:  " << (*it).m_Age<< endl; 
//    }

//    vector<Person*> v;
//    Person p1("aaa",10);
//    Person p2("bbb",20);
//    Person p3("ccc",30);
//    Person p4("ddd",40);
//    Person p5("eee",50);
//
//    v.push_back(&p1);
//    v.push_back(&p2);
//    v.push_back(&p3);
//    v.push_back(&p4);
//    v.push_back(&p5);
//
//    for (auto it = v.begin(); it != v.end(); it++)
//    {
//        cout << "Name: " << (*it)->m_Name << endl;
//        cout << "Age:  " << (*it)->m_Age << endl;
//    }



    //int i = 19;
    //while (i --> 0)
    //{
    //    cout << i << " ";
    //}

    vector< vector<int> > v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
     

    v1 = { 1,2,3,4 };
    v2 = { 2,3,4,5 };
    v3 = { 3,4,5,6 };
    v4 = { 4,5,6,7 };

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector< vector<int> >::iterator it = v.begin(); it != v.end(); ++it)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
     

    return 0;
}