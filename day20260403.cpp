//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <random>
//#include <ctime>
//
//#define TC_END "\033[0m"
//
//#define TC_RED "\033[1;31m"
//#define TC_GRN "\033[1;32m"
//#define TC_YLW "\033[1;33m"
//#define TC_BLU "\033[1;34m"
//
////void printNum(unsigned int n)
////{
////    cout << n % 10 << " ";
////    if (n >= 10)
////        printNum(n / 10);
////
////}
//int create_random_number()
//{
//    static std::default_random_engine engine(std::random_device{}());
//    static std::uniform_int_distribution<int> distribution(-10000,10000);
//    return distribution(engine);
//}
//
//namespace std{
//    int partition(int arr[], int l, int r)
//    {//假定l < r
//        int pivot = arr[l];
//        int j = l;
//        for (int i = l + 1; i <= r; ++i)
//        {
//            if (arr[i] < pivot)
//            {
//                swap(arr[++j],arr[i]);
//            }
//        }
//        swap(arr[j],arr[l]);
//        return j;
//    }
//    int __quick_select(int arr[], int l, int r, int k)
//    {
//        int s = partition(arr,l,r);
//        if (s == l + k - 1)
//            return s;
//        else if (s < l + k - 1)
//            return __quick_select(arr,s+1,r,k-s+l-1);
//        else
//            return __quick_select(arr,l,s-1,k); 
//    }
//    int quick_select_min(int arr[], int len, int k)
//    {
//        if (len < k)
//            return -1;
//        return __quick_select(arr, 0, len - 1, k);
//    }
//
//
//}/* namespace std */
//
//int main()
//{
//    int size;
//    //std::cout << TC_RED << "hello world" << std::endl;
//    //std::cout << TC_GRN << "hello world" << std::endl;
//    //std::cout << TC_YLW << "hello world" << std::endl;
//    //std::cout << TC_BLU << "hello world" << std::endl;
//
//    int arr1[200];
//    int arr2[200];
////    int arr1[20] = {-12, 25, -5, 30, -18, 7, 0, -22, 14, -30, 9, -7, 19, -3, 28, -14, 21, -9, 5, -27};
////    int arr2[20] = {-12, 25, -5, 30, -18, 7, 0, -22, 14, -30, 9, -7, 19, -3, 28, -14, 21, -9, 5, -27};
////    int k = 10;
////    size = 20;
////    int my_ret = std::quick_select_min(arr1,size,k);
////    std::nth_element(arr2,arr2+k-1,arr2+size);
////    int std_ret = arr2[k-1];
////    std::cout << "my_ret : "<< my_ret << std::endl;
////    std::cout << "std_ret : "<< std_ret << std::endl;
//
//
//
//    int flag = 0;
//    for (int i = 0; i <20000000; ++i)
//    {
//        int k,my_ret,std_ret;
//        size = (create_random_number() + 10000) % 200 + 1;
//        for (int j = 0; j < size; ++j)
//        {
//            arr1[j] = create_random_number();
//            arr2[j] = arr1[j];
//        }
//
//        std::cout << "Result " << i + 1 << " : " << "\n";
//        for (int w = 0; w < 20; ++w)
//        {
//            k = (create_random_number() + 10000) % size + 1;
//            int ret1 = std::quick_select_min(arr1, size, k);
//            if (ret1 > size - 1 || ret1 < 0)
//                std::cout << "error" << std::endl;
//            my_ret = arr1[ret1];
//            std::nth_element(arr2, arr2 + k - 1, arr2 + size);
//            std_ret = arr2[k-1];
//            if (std_ret == my_ret)
//            {
//                std::cout << TC_GRN << "true" << TC_END << " ";
//            }
//            else
//            {
//                std::cout << TC_RED << "false" << TC_END << " ";
//                flag = 1;
//            }
//            if (w == 9)
//                std::cout << "\n";
//        }
//        std::cout << "\n";
//    }
//    if (0 == flag)
//        std::cout << "no error occur" << std::endl;
//    else
//        std::cout << "error occur!!! please check your code!" << std::endl;
//    
//
////   printNum(1233);
//
//    
//
//    return -1;
//}
//

