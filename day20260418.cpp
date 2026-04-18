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


#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int min_num(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    return a;
}

int func(queue<int> que1, queue<int> que2, queue<int> que3) {
    //TODO
    
}

int main() {
    int m, n, k, x;
    queue<int> que1, que2, que3;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        cin >> x;
        que1.push(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        que2.push(x);
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        que3.push(x);
    }
    cout << func(que1, que2, que3) << endl;
    return 0;
}

