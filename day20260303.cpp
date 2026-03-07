#include <iostream>
#include <unistd.h>
#include <string>

//using namespace std;
using namespace std;

class Person
{
public:
    std::string getName()
    {
        return m_name;
    }
    std::string m_name;
    int m_salary;
    int m_age;
};
class divisionByZero_error:public std::exception
{
public:
    const char* what() const throw()
    {
        return "Division by Zero!";
    }
};

double division(double a,double b) noexcept(false)
{
    if (b == 0)
    {
        throw divisionByZero_error();
    }
    //if (b == 1)
    //{
    //    throw 1;
    //}
    return a / b; 
}

int main()
{
    std::bad_cast a;
    std::cout << a.what() << std::endl;

    int ret = 0;
    try
    {
        double ret = division(3, 0);
        std::cout << ret << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    catch (divisionByZero_error a)
    {
        cerr << a.what() << endl;
    }


    cout << "--------------------------" << endl;
    try
    {
        std::cout << typeid(int).name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << typeid(Person).name() << std::endl;

    //std::cout << std::endl;
    //ret = division(2,1);
    //std::cout << ret << std::endl;

    //catch (int errmsg)
    //{
    //    std::cout << errmsg << std::endl;
    //}

    return 0;
}