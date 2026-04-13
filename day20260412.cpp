//#include <iostream>
//
//using namespace std;
//
//int arr[10];
//bool vts[10];
//void print_one_result(int n) {
//    for (int i = 0; i < n; ++i) {
//        if (i) cout << " ";
//        cout << arr[i];
//    }
//    cout << endl;
//}
//
//void f(int i, int n)
//{
//    if (i == n) {
//        print_one_result(n);
//        return ;
//    }
//    for (int k = 1; k <= n; ++k) {
//        if (vts[k] == 1)
//            continue; 
//        vts[k] = 1;
//        arr[i] = k;
//        f(i + 1, n);
//        vts[k] = 0;
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    f(0,n);
//
//
//    return 0;
//}

//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <iomanip>
//using namespace std;
//
//#define S(a)  ((a) * (a))
//
//void f(long long n, long long d, long long& x, long long& y) {
//    if (n == 1) {
//        if (d == 1) x = 0, y = 0;
//        else if (d == 2) x = 0, y = 1;
//        else if (d == 3) x = 1, y = 1;
//        else x = 1, y = 0;
//        return ;
//    }
//    long long l = 1LL << (n - 1);
//    long long block = l * l; 
//    long long xx,yy;
//    if (d <= block) {
//        f(n - 1, d, xx, yy);
//        x = yy, y = xx;
//    } else if (d <= 2 * block) {
//        f(n - 1, d - block, xx, yy);
//        x = xx, y = yy + l;
//    } else if (d <= 3 * block) {
//        f(n - 1, d - 2 * block, xx, yy);
//        x = xx + l, y = yy + l;  
//    } else {
//        f(n - 1, d - 3 * block, xx, yy);
//        x = 2 * l - yy - 1, y = l - xx - 1;
//    }
//    return ;
//}
//
//int main()
//{
//    long long t,n,s,d;
//    cin >> t;    
//    vector<double> v;
//    for (long long i = 0; i < t; ++i) {
//        cin >> n >> s >> d;
//        long long sx,sy,dx,dy;
//        f(n,s,sx,sy);
//        f(n,d,dx,dy);
//        v.push_back((10 * sqrt(S(sx - dx) + S(sy - dy))));
//    }
//    for (const double& i : v) {
//        cout << fixed << setprecision(0) << i << endl;
//    }
//    return 0;
//}





#include <iostream>

#include <vector>
using namespace std;


//class vector
//{
//    int size;
//    int count;
//    int* data;
//public:
//    vector() {
//        size = 0;
//        count = 0;
//        data = nullptr;
//    }
//    ~vector() {
//        size = 0;
//        count = 0;
//        if (data != nullptr)
//        {
//            delete[] data;
//        }
//    }
//};
