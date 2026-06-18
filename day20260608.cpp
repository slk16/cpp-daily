//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//typedef struct Node {
//    int key;
//    int ltag,rtag;
//    struct Node* left, *right;
//}Node;
//Node* getNewNode(int key) {
//    Node* ret = (Node*)malloc(sizeof(Node));
//    ret->key = key;
//    ret->left = ret->right = NULL;
//    ret->ltag = ret->rtag = 0;
//    return ret;
//}
//Node* insert(Node* root, int key) {
//    if (root == NULL)
//        return getNewNode(key);
//    if (root->ltag == 0 && rand() % 2)
//        root->left = insert(root->left, key);
//    else if (root->rtag == 0)
//        root->right = insert(root->right, key); 
//    return root;
//}
//void clear(Node* root) {
//    if (root == NULL) 
//        return ;
//    if (root->ltag == 0) 
//        clear(root->left);
//    if (root->rtag == 0) 
//        clear(root->right);
//    free(root);
//    return ;
//}
//Node* pre_node = NULL;
//Node* inorder_first_root = NULL;
//void __thread_binary_tree(Node* inorder_root) {
//    if (inorder_root == NULL) return ;
//    if (inorder_root->ltag == 0) __thread_binary_tree(inorder_root->left);
//    if (inorder_first_root == NULL) inorder_first_root = inorder_root;
//    if (inorder_root->left == NULL) {
//        inorder_root->left = pre_node;
//        inorder_root->ltag = 1;
//    }
//    if (pre_node && pre_node->right == NULL) {
//        pre_node->right = inorder_root;
//        pre_node->rtag = 1;
//    }
//    pre_node = inorder_root;
//    if (inorder_root->rtag == 0) __thread_binary_tree(inorder_root->right);
//}
//void thread_binary_tree(Node* inorder_root) {
//    __thread_binary_tree(inorder_root);
//    pre_node->right = NULL;
//    pre_node->rtag = 1;
//}
//void pre_order(Node* root) {
//    if (root == NULL) return ;
//
//    printf("%d ", root->key); 
//    if (root->ltag == 0)
//        pre_order(root->left);
//    if (root->rtag == 0)
//        pre_order(root->right);
//}
//void in_order(Node* root) {
//    if (root == NULL) return ;
//    if (root->ltag == 0)
//        in_order(root->left);
//    printf("%d ", root->key);
//    if (root->rtag == 0)
//        in_order(root->right);
//}
//void post_order(Node* root) {
//    if (root == NULL) return ;
//    if (root->ltag == 0)
//        post_order(root->left);
//    if (root->rtag == 0)
//        post_order(root->right);
//    printf("%d ", root->key);
//}
//inline Node* next(Node* p) {
//    if (p->rtag == 1) {
//        return p->right;
//    } else {
//        Node* q = p->right;
//        while (q && q->ltag == 0 && q->left != NULL) {
//            q = q->left;
//        }
//        return q;
//    }
//}
//
//int main() {
//    srand(time(NULL));
//    Node* root = NULL;
//    for (int i = 0; i < 10; ++i) {
//        int value = rand() % (100 + 1);
//        root = insert(root, value);
//    }
//    thread_binary_tree(root);
//    pre_order(root);
//    printf("\n");
//    in_order(root);
//    printf("\n");
//    post_order(root);
//    printf("\n");
//
//    Node* p = inorder_first_root;
//    while (p) {
//        printf("%d ", p->key);
//        p = next(p); 
//    }
//    return 0;
//}

