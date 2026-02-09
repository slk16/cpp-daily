#include <iostream>
#include <chrono>


using namespace std;

void time(void (*)());
void swap_f(int& a, int& b);

void selection_sort(int arr[], int size)
{
    int min = 0;
    int temp = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < size; ++j){
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}
void bubble_sort(int arr[], int size)
{
    if (size < 2)
        return;
    if (arr == nullptr)
        return;
    for (int i = size - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1]){
                swap_f(arr[j],arr[j + 1]);
            }
        }
    }
}
int check_for_odd(int arr[], int size)
{
    int ret = 0;
    for(int i = 0; i < size - 1; ++i)
    {
        ret ^= arr[i];
    }
    return ret;
}
void test01() {

    int arr[1000] = { 1,9,5,2,6,4,3,7,8 };
    selection_sort(arr,9);


    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << " ";
    }

}
void test02() {
    int n = 10000000;
    int a = 0;
    for(int i = 0; i < n;++i)
    {
        a = 2+5;
        a = 4*7;
        a = 6*8;
    }
}
void test03() {
    int n = 10000000;
    int a = 0;
    for(int i = 0; i < n;++i)
    {
        a = 3 | 6;
        a = 3 & 4;
        a = 4 ^ 785;
    }

}
void test04()
{
    int arr[] = {5,6,9,2,4,8,3,7,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr,len);
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }

}
void test05()
{
    int a = 5;
    int b = 9;
    cout << "Before swap_f():" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap_f(a,b);
    cout << "After swap_f():" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
void test06()
{
    const int len = 10000;
    int arr[len] = { 0 };
    for (int i = 0; i < len; ++i)
    {
        arr[i] = len - i;
    }
    bubble_sort(arr,len);
    for (int j = 0; j < len; ++j)
    {
        cout << arr[j] << " ";
    }
}
void test07()
{
     
}

int main()
{
    // void test01();
    // time(test02);
    // time(test03);
    // test05();
    time(test06);

    cout << endl;
    return 0;
}

void time(void (*test)())
{
    auto start = std::chrono::steady_clock::now();
    test();
    auto end = std::chrono::steady_clock::now();
    auto last = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std:: endl << "\033[1;33m" << "execution time: " << last.count() << " microseconds" << "\033[0m" << std::endl;
}



void swap_f(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
//void test04_for02and03() {
//    auto start = std::chrono::steady_clock::now();
//    test02();
//    auto end = std::chrono::steady_clock::now();
//    auto last = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//    std::cout << "test02() execution time: " << last.count() << std::endl;
//
//    start = std::chrono::steady_clock::now();
//    test02();
//    end = std::chrono::steady_clock::now();
//    last = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//    std::cout << "test03() Execution time: " << last.count() << std::endl;
//
//}
