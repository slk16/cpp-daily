//海贼oj 595
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main() {
//    vector<string> s, st;
//    string target;
//    bool flag = 0;
//    int n;
//    cin >> n;
//    s.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> s[i];
//    }
//    cin >> target;
//    for (int i = 0; i < n; ++i) {
//        if (target == s[i]) {
//            st.push_back(target);
//            flag = 1;
//            break;
//        } else if (s[i] == "return") st.pop_back();
//        else st.push_back(s[i]);
//    }
//    if (flag) {
//        for (int i = 0; i < st.size(); ++i) {
//            if (i) cout << "->";
//            cout << st[i];
//        }
//    } else {
//        cout << "NOT REFERENCED" << endl;
//    }
//
//    return 0;
//}


//海贼oj 838
//#include <iostream>
//#include <cstdlib>
//#include <queue>
//using namespace std;
//
//int min_num(int a, int b, int c) {
//    if (a > b) swap(a, b);
//    if (a > c) swap(a, c);
//    return a;
//}
//
//int func(queue<int> que1, queue<int> que2, queue<int> que3) {
//    //TODO
//    int ans = 0x7f7f7f7f;
//    while (!que1.empty() && !que2.empty() && !que3.empty()) { 
//        int a = que1.front(), b = que2.front(), c = que3.front();
//        int temp_ans = abs(a-b) + abs(a-c) + abs(b-c);
//        if (temp_ans < ans) ans = temp_ans;
//        int min_temp = min_num(a,b,c);
//        if (min_temp == a) que1.pop();
//        else if (min_temp == b) que2.pop();
//        else que3.pop();
//    }
//    return ans;
//}
//
//int main() {
//    int m, n, k, x;
//    queue<int> que1, que2, que3;
//    cin >> m >> n >> k;
//    for (int i = 0; i < m; i++) {
//        cin >> x;
//        que1.push(x);
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        que2.push(x);
//    }
//    for (int i = 0; i < k; i++) {
//        cin >> x;
//        que3.push(x);
//    }
//    cout << func(que1, que2, que3) << endl;
//    return 0;
//}
//
//

//递归实现排列型枚举
//#include <iostream>
//using namespace std;
//int arr[20],vts[20];
//void output(int n) {
//    for (int i = 0; i < n; ++i) {
//        cout << arr[i]; 
//    }
//    cout << endl;
//}
//void func(int i, int n) {
//    if (i == n) {
//        output(n);
//        return ;
//    }
//    for (int j = 1; j <= n; ++j) {
//        if (vts[j]) continue;
//        vts[j]  = 1;
//        arr[i] = j;
//        func(i + 1,n);
//        vts[j] = 0;
//    }
//}
//
//int main(){
//    int n;
//    cin >> n;
//    func(0,3);
//
//    return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <stack>
//using namespace std;
//
//bool isValid(int arr[], int n) {
//    stack<int> s;
//    int x = 1;
//    for (int i = 0; i < n; ++i) {
//        if (s.empty() || s.top() < arr[i]) {
//            while (x <= arr[i]) {
//                s.push(x);
//                x++;
//            }
//        }
//        if (s.top() != arr[i]) return false;
//        s.pop();
//    }
//    return true;
//}
//int main() {
//    int n;
//    cin >> n;
//    int arr[25], cnt = 20;
//    for (int i = 0; i < n;++i) arr[i] = i + 1;
//    do {
//        if (isValid(arr, n)) {
//            for (int i = 0; i < n; ++i) {
//                cout << arr[i];
//            }
//            cout << endl;
//            cnt--;
//        }
//    }while(next_permutation(arr, arr+n) && cnt);
//    return 0;
//}

#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int x = 0, n = pushed.size();
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || s.top() != popped[i]) {
                while(x < pushed.size() && pushed[x] != popped[i]) {
                    s.push(pushed[x]);
                    x += 1;
                }
                if (x == pushed.size()) return false;
                s.push(pushed[x]);x += 1;
            }
            s.pop();
        }
        return true;
    }
}
