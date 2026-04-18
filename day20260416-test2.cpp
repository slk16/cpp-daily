// 使用链表实现的队列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct LinkList{
    Node head;
    Node* tail;
}LinkList;
typedef struct Queue{
    LinkList* list;
    int count;
}Queue;
Node* getNewNode(int val) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}
LinkList* initLinkList() {
    LinkList* l = (LinkList*)malloc(sizeof(LinkList));
    l->tail = &l->head;
    return l;
}
Queue* initQueue(){
    LinkList* l = initLinkList();
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list = l;
    q->count = 0;
    return q;
}
int emptyLinkList(LinkList* l) {
    if (l->head.next == NULL) return 1;
    return 0;
}
int empty(Queue* q) {
    return emptyLinkList(q->list);
}
int front(Queue* q) {
    if (emptyLinkList(q->list)) return -1;
    return q->list->head.next->data;
}
void push_back_linklist(LinkList* l, int val) {
    Node* p = getNewNode(val);
    l->tail->next = p;
    l->tail = l->tail->next;
    return ;
}
int push(Queue* q, int val) {
    if (q == NULL) return 0;
    push_back_linklist(q->list, val);
    q->count += 1;
    return 1;
}
void pop_front_linklist(LinkList* l) {
    Node* p = l->head.next;
    l->head.next = p->next;
    if (p == l->tail) l->tail = &l->head;
    free(p);
    return ;
}
int pop(Queue* q) {
    if (empty(q)) return 0;
    pop_front_linklist(q->list);
    q->count -= 1;
    return 1;
}
int clearLinkList(LinkList* l) {
    if (l == NULL) return 0;
    Node* q;
    for (Node* p = l->head.next;p;p = q) {
        q = p->next;
        free(p);
    }
    free(l);
    return 1;
}
int clearQueue(Queue* q) {
    if (q == NULL) return 0;
    clearLinkList(q->list);
    free(q);
    return 1;
}
void outputQueue(Queue* q) {
    for (Node* p = q->list->head.next;p;p = p->next) {
        printf("%d ", p->data);
    }
}
#define MAX_OP 30

#define TC_END "\033[0m"
#define TC_RED "\033[1;31m"
#define TC_GRN "\033[1;32m"
#define TC_YLW "\033[1;33m"
#define TC_BLU "\033[1;34m"
int main()
{
    Queue* q;
    srand(time(0));
    q = initQueue(); 
    for (int i = 0; i < MAX_OP; ++i) {
        int op = rand() % 5;
        int val;
        switch(op)
        {
        case 0:
        case 1:
            printf("front element: %d \n", front(q));
            pop(q);
            printf(TC_YLW "pop" TC_END " of queue \n");
            break;
        case 2:
        case 3:
        case 4:
            val = rand() % 100;
            push(q, val);
            printf(TC_YLW "push" TC_END " %d to Queue \n", val);
            break;
        }
        printf("Queue : ");
        outputQueue(q);
        printf("\n\n\n\n");
    }
    return 0;
}