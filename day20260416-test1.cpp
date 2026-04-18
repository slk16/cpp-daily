// 使用顺序表实现的队列
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_OP 20
#define ERR 0x80000000

#define TC_END "\033[0m"
#define TC_RED "\033[1;31m"
#define TC_GRN "\033[1;32m"
#define TC_YLW "\033[1;33m"
#define TC_BLU "\033[1;34m"

typedef struct Vector{
    int* data;
    int size;
    int count;
}Vector;
typedef struct Queue {
    Vector* data;
    int size,count,head,tail;
}Queue;
Vector* getNewVector(int size) {
    Vector* p = (Vector*)malloc(sizeof(Vector));
    p->data = (int*)malloc(sizeof (int) * size);
    p->size = size;
    p->count = 0;
    return p;
}
int insertVector(Vector* p, int pos, int val) {
    if (p == NULL) return ERR;
    if (pos < 0 || pos > p->count) return ERR;
    p->data[pos] = val;
    p->count += 1;
    return 1;
}
int seekVector(Vector* p, int pos) {
    return p->data[pos];
}
void clearVector(Vector* p) {
    if (p == NULL)
        return ;
    free(p->data);
    free(p);
    return ;
}
Queue* initQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = getNewVector(size);
    q->head = 0;
    q->tail = 0;
    q->size = size;
    return q;
}
int empty(Queue* q) {
    return q->count == 0;
}
int full(Queue* q) {
    return q->count == q->size;
}
int push(Queue* q, int val) {
    if (q == NULL || full(q)) return ERR;
    if (ERR == insertVector(q->data, q->tail, val)) return ERR;
    q->count += 1;
    q->tail += 1;
    if (q->tail == q->size) q->tail = 0;
    return 1;
}
int pop(Queue* q) {
    if (q == NULL || empty(q)) return ERR;
    q->head += 1;
    q->count -= 1;
    if (q->head == q->size) q->head = 0;
    return 1;
}
int front(Queue* q) {
    if (q == NULL || q->count == q->size) return ERR;
    return seekVector(q->data, q->head);
}
void clearQueue(Queue* p) {
    if (p == NULL) return ;
    clearVector(p->data);
    free(p);
    return ;
}
void outputQueue(Queue* q) {
    for (int i = 0; i < q->count; ++i) {
        printf("%d ", seekVector(q->data,q->head + i));
    }
}
int main()
{
    Queue* q;
    srand(time(0));
    q = initQueue(MAX_OP); 
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