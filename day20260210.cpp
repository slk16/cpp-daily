#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>

using namespace std;

#define TC_RED "\033[1;31m"
#define TC_GRN "\033[1;32m"
#define TC_YLW "\033[1;33m"
#define TC_BLU "\033[1;34m"
#define TC_NRM "\033[0m"

int my_strlen(char* str)
{
    if (str == nullptr)
        return -1;
    int count = 0;
    while(*str++ != 0) {
        ++count;
    }
    return count;
}
int myAtoi(const char* str)
{
    if (str == nullptr || *str == '\0')
        return 0;
    while(' ' == *str)
        ++str;
    int flag = 1;
    if (*str == '+')
        ++str;
    else if (*str == '-')
    {
        ++str;
        flag = -1;
    }
    long long ret = 0;
    while(*str >= '0' && *str <= '9')
    {
        ret = ret * 10 + flag * (*str - '0');

        if (ret > (int)0x7fffFFFF)
            ret = (long long)0x7fffFFFF;
        else if (ret < (int)0x80000000)
            ret = (long long)0x80000000;
        
        ++str;
    }
    return (int)ret;
}
char* gen(char* str, int n)
{
    if (n < 2  || str == nullptr)
        return nullptr;
    bool flag = false;
    if (n % 2 == 0)
        flag = true;
    std::default_random_engine e1((unsigned int)time(NULL) + n);
    std::uniform_int_distribution u1((int)0x80000000,(int)0x7fffFFFF);
    std::default_random_engine e((unsigned int)u1(e1));
    std::uniform_int_distribution<int> u(1,9);
    int sum = 0;
    for(int i = 0;i < n - 1; ++i)
    {
        int temp = u(e);
        if (flag && temp * 2 > 9)
            sum += temp * 2 - 9;
        else if (flag && temp * 2 <= 9)
            sum += temp * 2;
        else
            sum += temp;
        str[i] = temp + '0';
        flag = !flag;
    } 
    sum %= 10;
    sum = 10 - sum;
    str[n - 1] = (char)(sum + '0');
    str[n] = '\0';
    return str;
}

bool check(char* str, int len)
{
    int ret = 0;
    bool flag = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        if (flag)
            ret += (str[i] - '0') * 2 / 10 + (str[i] - '0') * 2 % 10;
        else
            ret += str[i] - '0';
        flag = !flag;
    }
    if (ret % 10 == 0)
        return true;
    else
        return false;
}

void test01()
{
    // std::cout << 11 + atoi("1324") << std::endl;
    const char* str[] = {
        "869558034360534",
        "352403057570038",
        "354875051700901",
        "352806053209171",
        "351618114721628",
        "356949116569011",
        "352605058818923",
        "353324094134399",
        "354001103532818",
        "353285040903163",
        "358928054479696",
        "867807038205282",
        "868568029288849",
        "354875057315761",
        "353988059711662",
        "4532015112830366"
    };
    for (int i = 0; i < 16; ++i)
    {
        int len = my_strlen((char*)str[i]);
        cout << TC_YLW << str[i] << " : "<<  check((char*)str[i], len) << "\033[0m" << endl;
    }

}
void test02()
{
    std::default_random_engine e((unsigned int)time(0));
    std::uniform_int_distribution<int> u(0,9);
    for (int i = 0; i < 20; ++i)
    {
        cout << u(e) << " ";
    }
}

void test03()
{
    std::default_random_engine e((unsigned int)time(0));
    std::uniform_int_distribution u(5,25);
    char* str;
    int len;
    bool flag = true;
    for (int i = 0; i < 100; ++i)
    {
        len = u(e);
        str = new char[len + 1]; 
        gen(str, len);
        std::cout << TC_YLW << "str: " << TC_NRM << setw(30) << std::left << str << TC_YLW << std::left << setw(5) << "len: " << TC_NRM << setw(4) << len << "  ";
        if (true == check(str,len))
            std::cout << TC_GRN << "true" << TC_NRM << std::endl;
        else
        {
            std::cout << TC_RED << "false" << TC_NRM<< std::endl;
            flag = false;
        }
        delete[] str;
    }
    if (flag)
    {
        cout << TC_GRN << "true" << TC_NRM << endl;
    }
    else
    {
        cout << TC_RED << "false" << TC_NRM << endl;
    }
}
void test04()
{
     
}


int main()
{
    // test03();
    test04();

    return 0;
}