#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;


// class add
//{
// public:
//     int operator()(int a,int b)
//     {
//         return a + b;
//     }
// };


int printSum(int a, int b)
{
#define Cout std::cout
#define Endl std::endl

    Cout << a + b << Endl;
    return a + b;
}


int main()
{
    //using veci = vector<int>;
    //veci v{1,2,3,4,5,6,7,8,9,10};
    //vector<int>::iterator i;
    ////方法一
    //for (i = v.begin();i != v.end();i++)
    //{
    //    cout << *i << " ";
    //}
    //cout << endl;
    //for (int i = 0; i < v.size();i++)
    //{
    //    cout << v[i] << " ";
    //}
    //cout << endl;
    //for (i = v.begin(); i < v.end(); i++)
    //{
    //    cout << *i <<" ";
    //}
    //cout << endl;

    //i = v.begin();
    //while(i < v.end())
    //{
    //    cout << *i << " ";
    //    i += 2;
    //}
    

//    list<int> lst1;
//    list<int> lst2(10);
//    list<char> lst3{'a', 'b', 'c', 'd', 'e'};
//    for(char x:lst3)
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//    list<int> lst4 = {1,2,3,4,5};
//    for(int x:lst4)
//    {
//        cout << x << "  ";
//    }
//    cout << endl;
//    lst2 = lst4;
//    for(int x:lst2)
//    {
//        cout << x << ' ';
//    }
//
//    int arr[] {1,2,3,4,5,6,7,8,9};
//
//    list<int> lst5;
//    lst5 = list<int>(arr, arr + 3);
//    for(int x: lst5)
//    {
//        cout << x << ' ';
//    }
//    cout << endl;
//    string s {"abcdefg"};
//    cout << s << endl;
//    list<char> lst6(s.begin(),s.end());
//    for (char ch : lst6)
//    {
//        cout << ch;
//    }
//
    int arr[] {1, 2, 3, 4, 5, 6};
    list<int> lst(arr,arr + sizeof(arr) / sizeof(arr[0]));
    //list<int>::iterator it;    
    //it = lst.begin();
    //while(it != lst.end())
    //{
    //    cout << *it << " ";

    //    it++;
    //}
    //反向遍历
    list<int>::reverse_iterator rit = lst.rbegin();
    for (;rit != lst.rend();++rit)
    {
        cout << *rit << ' ';
    }
    for (int x : lst)
    {
        cout << x << ' ';
    }
    





    //int a,b;
    //cout << "Enter two numbers:";
    //cin >> a >> b;
    //cout << "The result is " << add(a,b) << endl;
    

    return 0;
}
