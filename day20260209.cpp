#include <iostream>
#include <chrono>
#include <random>

using namespace std;
void time(void (*)());
int possess(int arr[], int left , int right);

int binary_find(int target, int arr[], int size)
{
    if (arr == nullptr || size < 2)
        return -1;
    int left = 0;
    int right = size - 1;
    int middle = 0;
    while(left <= right)
    {
        if (left + 1 == right);
        middle = (left - right) / 2 + right;
        if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        }

    }
    return left;
}

void insertion_sort(int arr[], int size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            for (int j = i; !(j == 0 || arr[j - 1] <= arr[j]); --j)
            {
                swap(arr[j],arr[j-1]);
            }
        }
    }
}


int check_for_1_even(int arr[], int size)
{
    if (arr == nullptr || size < 2)
    {
        return -1;
    }
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        ret ^= arr[i];
    }
    return ret;
}
int* check_for_2_even(int arr[], int size)
{
    if (arr == nullptr || size < 2)
    {
        return nullptr;
    }
    int eor = 0; 
    for (int i = 0; i < size ; ++i)
    {
        eor ^= arr[i];
    }
    int flag = eor;
    int eor2 = 0;
    flag &= (~eor + 1);
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] & flag != 0)
        {
            eor2 ^= arr[i];
        }
    }
    int* ret = new int[2];

    ret[0] = eor2;
    ret[1] = eor ^ eor2;
    return ret;
}

void test01()
{
//    for (int i = 0; i < 1000; ++i)
//    {
//        cout << "hello world" << endl;
//    }
    int arr[] = { 1,1,1,1,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,5 };
    int len = sizeof(arr) / sizeof(arr[0]);
    //int ret = check_for_1_even(arr,len);
    int* ret = nullptr;
    ret = check_for_2_even(arr,len);

    cout << "result1:  " << ret[0] << endl;
    cout << "result2:  " << ret[1] << endl;

    if (ret != nullptr)
    {
        delete[] ret;
        ret = nullptr;
    }

}

void test02()
{
    //插入排序
    int arr[] = { 5,6,8,4,2,3,1,9,7,2 }; 
    int len = sizeof(arr) / sizeof (arr[0]);
    cout << "length: " << len << endl;
    insertion_sort(arr,len);
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }

}
void test03()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int ret = binary_find(34,arr,len);
    cout << "result: " << ret << endl;
}
int getMax(int arr[], int size)
{
    return possess(arr, 0, size - 1);
}
int possess(int arr[], int left, int right)
{
    if (left == right)
        return arr[left];
    int middle = left + (right - left) >> 1;
    int leftMax = possess(arr,left,middle);
    int rightMax = possess(arr,middle + 1,right);
    return (leftMax > rightMax ? leftMax : rightMax);
}


void test04()
{
    
}



int main()
{
//    time(test01);
//    time(test02);
//    for (int i = 0; i < 50; ++i)
//    {
//        cout << i + 1 << ",";
//    }
//    time(test03);

    time(test04);

    return 0;
}


void time(void(*test)())
{
    auto start = std::chrono::steady_clock::now();
    test();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "\x1B[1;33m" << "Execution time: " << duration.count() << "\x1B[0m" << std::endl;
}