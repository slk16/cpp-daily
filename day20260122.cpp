#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
//容器 算法 迭代器
//仿函数 适配器 空间配置器

void print(int val)
{
    cout << val << endl;
}


int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //方法一

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    while(itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    cout << "---------------" << endl;
    //方法二

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "---------------" << endl;
    //方法三

    for_each(v.begin(),v.end(),print);
    
    return 0;
}