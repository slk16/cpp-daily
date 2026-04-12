//#include <iostream>
//using namespace std;
//
//int arr[10];
//
//void print_one_result(int n) {
//    for (int i = 0; i <= n; ++i) {
//        if (i) cout << " ";
//        cout << arr[i];
//    }
//    cout << endl;
//}
//void f(int i, int j, int n) {
//    if (j > n) return;
//    for (int k = j; k <= n; ++k) {
//        arr[i] = k;
//        print_one_result(i);
//        f(i + 1, k + 1, n);
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    f(0, 1, n);
//    return 0;
//}
//int arr[20];
//void print_one_result(int n) {
//    for (int i = 0; i <= n; ++i) {
//        if (i) cout << " ";
//        cout << arr[i];
//    }
//    cout << endl;
//}
//void f(int i, int j, int n, int w) {
//    if (i == w) {
//        print_one_result(w - 1);
//        return ;
//    }
//    for (int k = j; k <= n; ++k) {
//        arr[i] = k;
//        f(i + 1, k + 1, n + 1,w);
//    }
//}
//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    f(0,1,m - n + 1, n);
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <random>
//
//#define TC_END "\033[0m"
//#define TC_RED "\033[1;31m"
//#define TC_GRN "\033[1;32m"
//using namespace std;
//
//int create_random_number()
//{
//    static std::default_random_engine e(std::random_device{}());
//    static std::uniform_int_distribution u(-65535,65535);
//    return u(e);
//}
//
//void shell_sort(vector<int>& nums) {
//    if (nums.size() < 2)
//        return ;
//    for (int gap = nums.size() >> 1; gap > 0; gap >>= 1) {
//        for (int i = gap; i < nums.size(); ++i) {
//            int temp = nums[i];
//            int j;
//            for (j = i - gap; j >= 0 && nums[j] > temp; j -= gap) {
//                nums[j + gap] = nums[j];
//            }
//            nums[j + gap] = temp;
//        }
//    }
//    return ;
//}
//
//void __test()
//{
//    for (int i = 0; i < 100; ++i) {
//        int n = abs(create_random_number());
//        vector<int> test1;
//        vector<int> std__vec;
//        for (int i = 0; i < n; ++i) {
//            test1.push_back(create_random_number());
//        }
//        std__vec = test1;
//        sort(std__vec.begin(), std__vec.end());
//        shell_sort(test1);
//        if (std__vec == test1)
//            cout << "test " << i + 1  << " : " << TC_GRN << "True" << TC_END;        
//        else
//            cout << "test " << i + 1  << " : " << TC_RED << "False" << TC_END;        
//        cout << endl;
//    }
//}
//int main()
//{
//    __test();
//    return 0;
//}
