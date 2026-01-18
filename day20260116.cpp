#include <iostream>
#include <fstream>

using namespace std;

//int main(){
//    fstream fs;
//    string str;
//    system("chcp 65001");
//    
//    fs.open("D:\\cpp-code\\testfile\\test.txt", ios::out | ios::in);
//    //fs << "你好世界" << endl;
//    cin >> str;
//    fs << str;
//
//    fs.seekg(0);
//
//    fs >> str;
//    cout << str;
//    
//    fs.close();
//
//
//
//
//    return 0;
//}


// 函数模版注意事项 1、自动类型推导，必须推导出一致的数据类型才可以使用
//2、模版必须要确定出T的数据类型，才可以使用
template<typename T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';
    //cout << "交换前：" << endl
    //<< "a = " << a << endl
    //<< "b = " << b << endl;
    //Swap(a,b);
    //cout << "交换后：" << endl
    //<< "a = " << a << endl
    //<< "b = " << b << endl;

    //Swap(a,c);// error

}

//template<class T>
//void func(){
//    cout << "func() call "<< endl;
//}
//void test02()
//{
//    //func();// error 必须指出数据类型
//    func<int>();
//}
template<class T>
void selection_sort(T arr[], int len, int (&compareFunc)(T elem1, T elem2)){

    for (int i = 0; i < len - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (compareFunc(arr[j], arr[min]) < 0)
            {
                min = j;
            }
            
        }
        if (min == i)
            continue;
        Swap(arr[i], arr[min]);
    }
}
int char_compare(char a, char b)
{
    return (int)(a - b);
}
int int_compare(int a, int b)
{
    return (a - b);
}
template<class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << arr[i] << ' ';
    }
}

int main(){
//   test02();
    char charArr[] = "badcfehidddadfsf";
    int charArrLen = sizeof(charArr) - 1;
    selection_sort(charArr,charArrLen,char_compare);

    // test01<int>(); // 对于非函数模版，不可指定类型

    printArray(charArr,charArrLen);

    cout << endl;

    int intArr[] = {1,5,3,2,5};
    int intArrLen =  sizeof(intArr) / sizeof(int);
    selection_sort<int>(intArr,intArrLen,int_compare);
    printArray<int>(intArr,intArrLen);

    //cout << charArr << endl;




    return 0;
}