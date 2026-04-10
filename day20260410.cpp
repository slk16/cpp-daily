//#include <iostream>
//using namespace std;
//int main()
//{
//    int a,b,c;
//    for (int i = 100; i < 1000; ++i) {
//        a = i / 100;
//        b = (i - a * 100) / 10;
//        c = i - a * 100 - b * 10;
//        if (a * a * a + b * b * b + c * c * c == i)
//            cout << i << " ";
//    }
//
//    return 0;
//}


#include <iostream>
using namespace std;

int f(int n) {
    if (n == 1)
        return 1;
    return n * f(n-1);
}
int main()
{
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;
    }
    cout << sum << endl;

    cout << "Result : " << f(10) << endl;

    return 0;
}























//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    char* str[20];
//    gets(str);

//    return 0;
//}