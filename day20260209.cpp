#include <iostream>
#include <chrono>

using namespace std;
void time(void (*)());

int check_for_1_even(int arr[], int size)
{
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        ret ^= arr[i];
    }
    return ret;
}
int check_for_2_even(int arr[], int size)
{
    
}

void test01()
{
//    for (int i = 0; i < 1000; ++i)
//    {
//        cout << "hello world" << endl;
//    }
    int arr[] = { 1,1,1,1,2,2,2,3,3,3,3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int ret = check_for_1_even(arr,len);
    cout << "result:  " << ret << endl;
    

}

int main()
{
    time(test01);

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