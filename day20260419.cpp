//#include <iostream>
//#include <stack>
//
//using namespace std;
//#define MAX_CH 10000
//
//char str[MAX_CH + 5];
//int match[MAX_CH + 5];
//
//int main() {
//    cin >> (str + 1);
//    int i = 1;
//    stack<int> s;
//    while(str[i]) {
//        switch(str[i]) {
//        case '(':
//        case '[':
//        case '{':
//            s.push(i); 
//        break;
//        case ')': {
//            if (!s.empty() && str[s.top()] == '(') {
//                match[s.top()] = i;
//                s.pop();
//            } else
//                s.push(i);
//        } break;
//        case ']': {
//            if (!s.empty() && str[s.top()] == '[') {
//                match[s.top()] = i;
//                s.pop();
//            } else
//                s.push(i);
//        } break;
//        case '}': {
//            if (!s.empty() && str[s.top()] == '{') {
//                match[s.top()] = i;
//                s.pop();
//            } else
//                s.push(i);
//        } break;
//        }
//        ++i;
//    }
//    //for (int i = 1; i < 10; ++i) {
//        //cout << "match[" << i << "] = " << match[i] << endl;
//    //}
//    i = 1;
//    int temp_ans = 0, ans = 0;
//    while (str[i]) {
//        if (match[i]) {
//            temp_ans += match[i] - i + 1;
//            i = match[i] + 1;
//        }
//        else {
//            ++i;
//            temp_ans = 0;
//        }
//        if (temp_ans > ans) ans = temp_ans;
//    }
//    cout << ans << endl;
//    return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <cmath>
//
//#define INF 0x6f6f6f6f
//using namespace std;
//int calc(string& str, int l, int r) {
//    int cur_pri, pos = -1, min_pri = INF, pre_pri = 0;
//    bool flag = 1;
//    for (int i = l; i <= r; ++i) {
//        switch (str[i]) {
//        case '(': 
//            pre_pri += 100;
//            flag = 1;
//            continue;
//        case ')': 
//            pre_pri -= 100;
//            continue;
//        case '+':
//        case '-': 
//            if (flag) {
//                cur_pri = 1000;
//                flag = 0;
//                break;
//            }
//            flag = 1;
//            cur_pri = 1 + pre_pri;
//            break;
//        case '*':
//        case '/': 
//            flag = 1;
//            cur_pri = 2 + pre_pri;
//            break;
//        case '^': 
//            flag = 1;
//            cur_pri = 3 + pre_pri;
//            break;
//        default:
//            cur_pri = INF + 5;
//            flag = 0;
//            break;
//        }
//        if (cur_pri <= min_pri) {
//            min_pri = cur_pri;
//            pos = i;
//        }
//    }
//    if (pos == -1){
//        int num = 0;
//        for (int i = l; i <= r; ++i) {
//            if (str[i] >= '0' && str[i] <= '9')
//                num = num * 10 + (str[i] - '0');
//        }
//        return num;
//    }
//    else if (pos == 0) {
//        int num = 0;
//        int flag = 1;
//        for (int i = l; i <= r; ++i) {
//            if (str[i] >= '0' && str[i] <= '9')
//                num = num * 10 + (str[i] - '0');
//            if (str[l] == '-') flag = -1;
//        }
//        return num * flag;
//    }
//    else {
//        int a = calc(str,l,pos - 1);
//        int b = calc(str,pos + 1, r);
//        switch(str[pos]) {
//        case '+': return a + b;
//        case '-': return a - b;
//        case '*': return a * b;
//        case '/': return a / b;
//        case '^': return pow(a,b);
//        }
//    }
//    return 0;
//}
//int main() {
//    string str;
//    cin >> str;
//    int ret = calc(str,0,str.size() - 1);
//    cout << ret << endl;
//
//    return 0;
//}
//
//


