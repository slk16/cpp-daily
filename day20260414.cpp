//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//#define TC_END "\033[0m"
//#define TC_RED "\033[1;31m"
//#define TC_GRN "\033[1;32m"
//#define TC_YLW "\033[1;33m"
//#define TC_BLU "\033[1;34m"
//
//#define DL 3
//#define STR(n) #n
//#define DIGIT_LEN_STR(n) "%" STR(n) "d"
//#define ARROW_LEN 4
//
//typedef struct Node {
//    int data;
//    Node *next;
//}next;
//Node* getNewNode(int val) {
//    Node* p = (Node* )malloc(sizeof(Node));
//    p->data = val;
//    p->next = NULL;
//    return p;
//}
//Node* insert(Node* head, int pos, int val) {
////    if (pos == 0) {
////        Node* p = getNewNode(val);
////        p->next = head;
////        return p;
////    }
////    Node*p = head;
////    for (int i = 0; i < pos - 1; ++i) {
////        if (p == NULL) return NULL;
////        p = p ->next;
////    }
////    Node* s = getNewNode(val);
////    s->next = p ->next;
////    p->next = s;
////    return head;
//    Node vhead, *p = &vhead, *node = getNewNode(val);
//    vhead.next = head;
//    for (int i = 0; i < pos; ++i) {
//        p = p -> next;
//    } 
//    node -> next = p -> next;
//    p ->next = node;
//    return vhead.next;
//}
//Node* find(Node* head, int val, int* ppos)
//{
//    int i = 0;
//    for (Node* p = head;p;p = p->next) {
//        if (p -> data == val) {
//            *ppos = i;
//            return p;
//        }
//        ++i;
//    }
//    *ppos = -1;
//    return NULL;
//}
//void clear(Node* head) {
//    if (head == NULL) return ;
//    for(Node* p = head,*q;p;p = q) {
//        q = p->next;
//        free(p);
//    }
//    return ;
//}
//void outputLinkList(Node* head, int pos) {
//    int i = 0;
//    int len =  0;
//    for (Node* p = head;p;p = p -> next) {
//        len += printf("%3d", i);
//        len += printf("    ");
//        ++i;
//    }
//    printf("\n");
//    for (int i = 0; i < len; ++i) {
//        printf("-");
//    } 
//    printf("\n");
//    for (Node* p = head; p; p = p->next) {
//        printf(DIGIT_LEN_STR(DL), p->data);
//        printf(" -> ");
//    }
//    printf("\n  ");
//    if (pos != -1)
//    {
//        for (int i = 0; i < pos; ++i) {
//            printf("       ");
//        }
//        printf("^\n  ");
//        for (int i = 0; i < pos; ++i) {
//            printf("       ");
//        }
//        printf("|\n");
//    }
//    printf("\n\n\n");
//}
//int main()
//{
//    srand(time(0));
//    #define MAX_OP 20
//    int op, val, tar, pos, count = 0;
//    Node* head = NULL;
//    for (int i = 0; i < MAX_OP; ++i) {
//        int op = rand() % 5;
//        switch(op) {
//            case 0:
//            case 1:
//            case 2:
//            case 3:
//                pos = rand() % (count + 1);
//                val = rand() % 100;
//                head = insert(head,pos,val);
//                printf(TC_YLW "insert" TC_END " %d at %d to LinkList\n", val, pos);
//                ++count;
//                outputLinkList(head, -1);
//                break;
//            case 4:
//                printf("Enter your target:\n");
//                scanf("%d", &tar); 
//                Node* p = find(head,tar,&pos);
//                outputLinkList(head, pos);
//                printf(TC_YLW "find" TC_END " %d at %d in LinkList\n", tar, pos);
//                printf("\n\n\n");
//                break;
//        }
//    }
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    return 0;
}

