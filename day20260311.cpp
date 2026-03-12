#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <deque>


using namespace std;



int main( )
{ 
    list<int> lt;
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i + 1);
    }
    //cout << "v.max_size() : " << v.max_size() << endl;
    v[4] = 15;
    //for (int i : v)
    //{
    //    cout << i << " ";
    //}
    //cout << endl;
    //cout << "v.size() : " << v.size() << endl;
    //cout << "v.capacity() : " << v.capacity() << endl;
    //---------------------------------------------------
    stack<int> st;

    queue<int> q;
    for (int i = 1; i <= 5; ++i)
    {
        q.emplace(i);
        cout << "q.emplace(" << i << ")" << endl;
    }
    cout << endl;
    cout << "q.front() : " << q.front() << endl;
    cout << "q.back() : " << q.back() << endl;

    cout << endl;
    q.push(2);
    cout << "q.push(2)" << endl;
    //for (int i : q) { } // stack queue不支持迭代器
    cout << "q.front() : " << q.front() << endl;
    cout << "q.back() : " << q.back() << endl;

    cout << endl;
    cout << "q.pop(" << q.front() << ")" << endl;
    q.pop();
    cout << "q.front() : " << q.front() << endl;
    cout << "q.back() : " << q.back() << endl;
    cout << endl;
    
    cout << "q.pop(" << q.front() << ")" << endl;
    q.pop();
    cout << "q.front() : " << q.front() << endl;
    cout << "q.back() : " << q.back() << endl;

    priority_queue<int> pq;
    for (int i = 1; i <= 5; ++i)
    {
        pq.emplace(i);
    }
    while(pq.empty() != true)
    {
        cout << pq.top() << " ";
        pq.pop();
    }





    

    
    

    return 0;
}