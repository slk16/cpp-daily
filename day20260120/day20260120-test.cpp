#include "day20260120.h"

template <class NameType, class AgeType>
Person<NameType,AgeType>::Person(NameType name, AgeType age)
{
    m_Name = name;
    m_Age = age;
}
template <class NameType, class AgeType>
void Person<NameType,AgeType>::showInfo()
{
    cout << "Name: " << m_Name <<endl 
    << "Age:  " << m_Age << endl;
}