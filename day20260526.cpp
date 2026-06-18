//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//typedef struct Node
//{
//    int data;
//    int ltag,rtag;
//    struct Node* left,*right;
//}Node;
//Node* getNewNode(int data) {
//    Node* p = (Node*)malloc(sizeof(Node));
//    p->data = data;
//    p->left = NULL;
//    p->right = NULL;
//    p->rtag = p->ltag = 0;
//    return p;
//}
//Node* insert(Node* root, int data) {
//    if (root == NULL) return getNewNode(data);
//    Node* ret;
//    if (rand() % 2) root->left = insert(root->left, data);
//    else root-> right= insert(root->right, data);
//    return root;
//}
//void pre_order(Node* root) {
//    if (root == NULL) return ;
//    printf("%d ", root->data);
//    if(root->ltag == 0)pre_order(root->left);
//    if(root->rtag == 0)pre_order(root->right);
//}
//void in_order(Node* root) {
//    if (root == NULL) return ;
//    if(root->ltag == 0)in_order(root->left);
//    printf("%d ", root->data);
//    if(root->rtag == 0)in_order(root->right);
//}
//void post_order(Node* root) {
//    if(root == NULL) return ; 
//    if(root->ltag == 0) post_order(root->left);
//    if(root->rtag == 0) post_order(root->right);
//    printf("%d ", root->data);
//}
//Node* inorder_root = NULL;
//Node* __build_inorder_thread(Node* root) {
//    static Node* pre_node = NULL;
//    if (root == NULL) return pre_node;
//    if (root->ltag == 0) __build_inorder_thread(root->left);
//    if (inorder_root == NULL) inorder_root = root;
//    if (root->left == NULL)
//    {
//        root->left = pre_node;
//        root->ltag = 1;
//    }
//    if (pre_node && pre_node->right == NULL)
//    {
//        pre_node->right = root;
//        pre_node->rtag = 1;
//    }
//    pre_node = root; 
//    if (root->rtag == 0) __build_inorder_thread(root->right);
//    return pre_node;
//}
//void build_inorder_thread(Node* root) {
//    Node* pre_node = __build_inorder_thread(root);
//    pre_node->rtag = 1;
//    pre_node->right = NULL;
//}
//void clear(Node* root) {
//    if(root->ltag == 0)clear(root->left);
//    if(root->rtag == 0)clear(root->right);
//    free(root);
//}
//Node* getNext(Node* p) {
//    if (p->rtag == 1) return p->right;
//    if (p->right == NULL) return NULL;
//    Node* n = p->right;
//    while(n->ltag == 0 && n->left) {
//        n = n->left;
//    }
//    return n;
//}
//int main() {
//    srand(time(0));
//    Node* root = NULL;
//    for (int i = 0; i < 10; ++i) {
//        root = insert(root,rand() % 100);
//    }
//    build_inorder_thread(root);
//    pre_order(root);
//    printf("\n");
//    in_order(root);
//    printf("\n");
//    post_order(root);
//    printf("\n");
//    Node* p = inorder_root;
//    while(p){
//        printf("%d ",p->data);
//        p = getNext(p);
//    }
//    return 0;
//}
#include <iostream>
int main() {


    return 0;
}
