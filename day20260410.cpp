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
#include <vector>
using namespace std;

//int tz(int n) {
//    if (n == 1)
//        return 1;
//    return 2 * tz(n - 1) + 2;
//}
//
//int f(int n) {
//    if (n == 1)
//        return 1;
//    return n * f(n-1);
//}


int f(int i, vector<int>& arr, int n)
{
    if (i >= n)
        return 0;
    return f(i + arr[i], arr, n) + 1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        arr.push_back(a);
    }
    cout << "Result : " << f(0, arr, n) << endl;





//    int sum = 0;
//    for (int i = 1; i <= 100; ++i) {
//        sum += i;
//    }
//    cout << sum << endl;
//
//    cout << "Result : " << f(10) << endl;

//    cout << "tzsl : " <<  tz(10) << endl;;


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