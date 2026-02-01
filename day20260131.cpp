#include <iostream>

using namespace std;

//class Num
//{
//public:
//    int m_arr[1000];
//    int m_size;
//
//    Num(int* arr,int size)
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            m_arr[i] = arr[i];   
//        }
//        m_size = size;
//    }
//
//};

void trans(char carr[1000],int len_carr,int arr[1000],int& len_arr)
{
    int count = 0;
    for (int i = 0; i < len_carr; ++i)
    {
        arr[i] = carr[i] - '0';
    }

    len_arr = len_carr;
}

int* divide_big_by_small(int arr[],int len_arr,int b,int& ret_len,int& ret_remainder)
{
    int* ret = new int[1000];
    ret_len = 0;
    ret_remainder = 0;

    for (int i = 0; i < len_arr; ++i)
    {
        ret[i] = (arr[i] + ret_remainder * 10) / b;
        ret_remainder = (arr[i] + ret_remainder * 10) % b;        
        ret_len++;
    }

    return ret;
}
int* divide_big_by_big(int arr1[],int len_arr1,int )
{
    
}

int main()
{
    int b,len_carr = 0,len_arr = 0;
    char ch;
    char carr[1000];
    int arr[1000];
    for (int i = 0; i < 1000; ++i)
    {
        arr[i] = 0;
        carr[i] = 0;
    }  

    int i = 0;

    cout << "Enter a big number: " << endl;
    while('\n' != (ch = cin.get())){
        carr[i] = ch;
        ++len_carr;
        ++i;
    }

    cout << "Enter a small number: " << endl;
    cin >> b;

    trans(carr,len_carr,arr,len_arr);

//    for (int i = 0; i < len_arr; ++i)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl << "len_arr: " << len_arr << endl;


    int ret_len,ret_remainder;
    int* ret = divide_big_by_small(arr,len_arr,b,ret_len,ret_remainder);
    cout << "ret:  ";
    for (int i = 0; i < ret_len; ++i)
    {
        cout << ret[i];
    }
    cout << endl
    << "ret_len:  " << ret_len << endl
    << "ret_remainder:  " << ret_remainder << endl;

    

    return 0;
}