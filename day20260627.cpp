//#include <stdio.h>
//int main() {
//  int i = 0;
//  int n = 0;
//  
//  scanf("%d %d", &i, &n);
//  if (n == 16) {
//    printf("%x\n", i);
//  } else if (n == 8){
//    printf("%o\n", i);
//  } else if (n == 10) {
//    printf("%d\n", i);
//  }
//}
//#include <stdio.h>
//void print(int arr[], int n) {
//  	for (int i = 0; i < n; ++i) {
//      	printf("%d ", arr[i]);
//    }
//}
//void swap(int *l, int *r) {
//  	int temp = *l;
//  	*l = *r;
//  	*r = temp;
//}
//int main() {
//  	int arr[1024] = { 0 };
//  	int n = 0, trans;
//  	scanf("%d", &n);
//  	for (int i = 0; i < n; ++i) {
//      	scanf("%d", &trans);
//      	arr[i] = trans;
//    }
//  	if (n < 2) {
//		print(arr,n);
//      	return 0;
//    }
//  	
//  	for (int i = 0; i < n; ++i) {
//      	int p = i, j = i, min = arr[i];
//      	for (; j < n; ++j) {
//          	if (arr[j] < min) {
//             	p = j;
//              	min = arr[j];
//            }
//        }
//      	swap(&arr[i], &arr[p]);
//    }
//    print(arr,n);
//  
//  	return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//
//int main() {
//    using std::vector;
//    using std::string;
//    vector<int> v1;
//    vector<int> v2(10);
//    vector<int> v3(10,42);
//    vector<int> v4{10};
//    vector<int> v5{10,42};
//    vector<string> v6{10};
//    vector<string>v7{10,"hi"};
//    auto s = v7.size();
//    vector<string>::size_type t = s;
//
//    return 0;
//}

#include <iostream>

using std::cin;
using std::cout,std::endl;
int main() {
    int a,b,c = 0;
    int d = 0,e,f = 0;
    cin >> a >> b >> c;
    if (c == 3)
        cout << "Stream is valid" << endl;
    else
        cout << "Stream is invalid" << endl;
    cin >> d >> e >> f;
    if (c == 3)
        cout << "Stream is valid" << endl;
    else
        cout << "Stream is invalid" << endl;

    return 0;
}