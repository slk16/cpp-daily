//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#define MAX_ 10
//
//typedef struct Node {
//    int key;
//    Node* left,*right;
//}Node;
//Node* getNewNode(int key) {
//    Node* p = (Node*)malloc(sizeof(Node));
//    p->key = key;
//    p->left = p->right = NULL;
//    return p;
//}
//Node* insert(Node* root, int key) {
//    if (root == NULL) {
//        Node* p = getNewNode(key);
//        return p;
//    }
//    if (rand() % 2) {
//        root->left = insert(root->left, key);
//    } else {
//        root->right = insert(root->right, key);
//    }
//    return root;
//}
//void bfs(Node* root) {
//    if (root == NULL) return ;
//    Node* que[MAX_ + 5] = {0};
//    int head = 0,tail = 0;
//    que[tail++] = root;
//    while(head < tail) {
//        printf("Node : %d\n", que[head]->key);
//        if (que[head]->left) {
//            printf("\t%d->%d (left)\n", que[head]->key, que[head]->left->key);
//            que[tail++] = que[head]->left;
//        }
//        if (que[head]->right) {
//            printf("\t%d->%d (right)\n", que[head]->key, que[head]->right->key);
//            que[tail++] = que[head]->right;
//        }
//        printf("\n\n");
//        head++;
//    }
//    printf("bfs finish !\n\n\n");
//    return ;
//}
//int tot = 0;
//void dfs(Node* root) {
//    int start, end;
//    tot += 1;
//    start = tot;
//    if (root->left) dfs(root->left); 
//    if (root->right) dfs(root->right);
//    tot += 1;
//    end = tot;
//    printf("Node: %d [%d -> %d]\n", root->key, start, end);
//    return ;
//}
//
//void clear(Node* root) {
//    if (root == NULL)
//        return ;
//    clear(root->left);
//    clear(root->right);
//    free(root);
//    return ;
//}
//int main(){
//    srand(time(0));
//    Node* root = NULL;
//    for (int i = 0; i < MAX_; ++i) {
//        root = insert(root, rand() % 100);
//    }
//    bfs(root);
//    dfs(root);
//
//    clear(root);
//    return 0;
//}

#include <stdio.h>
int main(){ 
    double temp;
    double sum = 0.0;
    int flag = 1;
    int i = 1;
    while(1) {
        temp = 1.0 / i;  
        sum += temp * flag;
        if (temp < 1e-6) break;
        i += 2;
        flag = -flag;
    }
    printf("%.6f", 4*sum);
    return 0;
}


//#include <stdio.h>
//int main() {
//    char arr[1024];
//    int temp;
//    int i = 0;
//    while ('\n' != (temp = getchar())) {
//        arr[i++] = (char)temp;
//    }
//    arr[i] = '\0';
//    int len = i;
//    for (int j = len - 1; j >= 0; --j) {
//        putchar(arr[j]);
//    }
//    return 0;
//}