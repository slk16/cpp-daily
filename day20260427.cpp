//#include <stdio.h>
//void swap(int* pa, int* pb) {
//    int temp = *pa;
//    *pa = *pb;
//    *pb = temp;
//}
//void sort(int arr[], int n) {
//    if (n < 2) return;
//    for (int i = 0; i < n; ++i) {
//        int min = arr[i], pos = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (arr[j] < min) {
//                min = arr[j];
//                pos = j;
//            }
//        }
//        swap(arr + pos,arr + i);
//    }
//}
//
//int main()
//{
//    int n, temp;
//    int arr[1024] = { 0 };
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &temp);
//        arr[i] = temp;
//    }
//    sort(arr,n);
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main() {
//    int arr[] = {20,45,78,32,87},size = 5;
//    int n;
//    int i = 0;
//    scanf("%d", &n);
//    while (i < size && arr[i] != n) {
//        ++i;
//    }
//    if (i < size) {
//        for (int j = i; j < size - 1; ++j) {
//            arr[j] = arr[j + 1];
//        }
//        --size;
//        for (int i = 0; i < size; ++i) {
//            printf("%d ", arr[i]);
//        }
//    }
//    return 0;
//}