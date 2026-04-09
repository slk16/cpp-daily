#include <iostream>
#include <vector>
using namespace std;
class Date
{
public:
    Date(int y = 0): year(y){}
    explicit Date(int y, int m): year(y),month(m){}

private:
    int year;
    int month = 4;
    int date = 5;
};

int main()
{
    Date d1(25);
    //Date d2 = 26;
    Date d3 = Date(27);

    vector<int> v;
    

    //char arr[] = "hello world";
    //char* pa = arr;
    //cout << *pa << endl;
    //cout << arr << endl;

    //const char (*parr)[] = &"hello world";
    //cout << *parr << endl;





    return 0;
}