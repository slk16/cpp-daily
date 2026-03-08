#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
    string m_name;
    int m_age;
    Person(string& name, int age):m_name(name),m_age(age){};
};
void show(const Person& p)
{
    cout << "name : " << p.m_name << endl
    << "age : " << p.m_age << endl;
}

void print(list<int>& lt)
{
    for (int x : lt)
    {
        cout << x << " ";
    }
    cout << endl;
}
int add(const int a, const int b)
{
    return a + b;
}

int main()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    cout << "size = " << lt.size() << endl;
    lt.resize(10);
    cout << "new size = " << lt.size() << endl;
    print(lt);
    
    cout << endl << "------------------" << endl;
    lt.resize(5);
    cout << "new size = " << lt.size() << endl;
    print(lt);
    
    cout << endl << "------------------" << endl;
    lt.resize(10,8);
    cout << "new size = " << lt.size() << endl;
    print(lt);

    cout << endl << "------------------" << endl;
    if (lt.empty())
    {
        cout << "lt.empty(): true" << endl;
    }
    else
    {
        cout << "lt.empty(): false" << endl;
    }
    lt.resize(0);
    if (lt.empty())
    {
        cout << "lt.empty(): true" << endl;
    }
    else
    {
        cout << "lt.empty(): false" << endl;
    }
    cout << endl << "------------------" << endl;
    cout << "sizeof lt is " << sizeof (lt) << endl;
    cout << endl << "------------------" << endl;
    for (int i = 0; i < 10; ++i)
    {
        lt.push_back(i + 1);

    }
    print(lt);
   
    cout << endl << "------------------" << endl;
    cout << "lt.front: " << lt.front() << endl;
    cout << "lt.back: " << lt.back() << endl;

    cout << endl <<  "lt.push_front(11) " << endl;
    lt.push_front(11);
    cout << "lt.front: " << lt.front() << endl;
    cout << "lt.size: " << lt.size() << endl;
    cout << endl << "lt.pop_front()" << endl;
    lt.pop_front();
    cout << "lt.front: " << lt.front() << endl;
    cout << "lt.size: " << lt.size() << endl;
    cout << endl << "lt.pop_back()" << endl;
    cout << "lt.front: " << lt.front() << endl;
    cout << "lt.back: " << lt.back() << endl;
    cout << "lt.size: " << lt.size() << endl;
    cout << "lt.maxsize: " << lt.max_size() << endl;
    
    cout << endl << "------------------" << endl;
    print(lt);
    cout << endl;

    using li = list<int>; 
    li::iterator it;// list<int>::iterator it;
    li::iterator itret;
    it = ++lt.begin(); 
    lt.insert(it,3,5);
    it++;
    itret = lt.insert(it,10);
    print(lt);
    cout << "new element: " << *itret << endl;

    int ret = 0;
    int a = 2,b = 3;
    ret = add(10,20);
    cout << "The result of add() is " << ret << endl;
    ret = add(a,b);
    cout << "The result of add() is " << ret << endl;

    cout << "---------------------------" << endl;

    string person1Name("zhangsan");
    string person2Name("lisi");
    Person p(person1Name, 20);
    p = Person(person2Name,18);
    show(p);

    cout << "---------------------------" << endl;
    print(lt);
    li::iterator it1 = lt.begin(),it2 = lt.begin(),it3 = lt.begin();
    ++it1;
    while(*it2 != 3) {
        ++it2;
    }
    cout << "*it1 is " << *it1 << endl;
    cout << "*it2 is " << *it2 << endl;
    lt.erase(it1--);
    print(lt);
    cout << endl;
    ++it3;
    lt.erase(++it1,it2);
    print(lt);

    cout << endl << "------------------" << endl;
    lt.clear();
    print(lt);
    cout << endl << "------------------" << endl;

    



    cout << endl;
    return 0;
}