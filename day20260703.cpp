#include <iostream>
#include <string>
#include <memory>

namespace slk {
class Person{
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
public:
    Person() {}
    Person(std::string name, int age) {
        m_name = name;
        m_age = std::make_unique<int> (age);
    }
    Person(const Person& p) {
        m_name = p.m_name;
        m_age = std::make_unique<int> (*p.m_age);
    }    
    Person(Person&& p) {
        m_name = std::move(p.m_name);
        m_age = std::move(p.m_age);
    }
    Person& operator=(const Person& p) {
        m_name = p.m_name;
        m_age = std::make_unique<int>(*p.m_age);
        return *this;
    }
    Person& operator=(Person&& p) {
        m_name = std::move(p.m_name);
        m_age = std::move(p.m_age);
        return *this;
    }
private:
    std::string m_name;
    std::unique_ptr<int> m_age;
};
std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << p.m_name;
    if (p.m_age != nullptr)
        out << " " << *p.m_age;
    return out;
}

} // namespace slk
using slk::Person;
void test_move() {
    Person p1("xiaohong", 12);
    Person p2 = std::move(p1);
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
}
void test() {
    Person p1("xiaoming", 28);
    std::cout << p1 << std::endl;
    Person p2;
    p2 = p1;
    std::cout << p2 << std::endl;
}
int main() {
    test_move();


    return 0;
}