#include <iostream>

using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age);
    void showInfo();
    NameType m_Name;
    AgeType m_Age;
};