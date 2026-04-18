#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    char *data;
    int size, top;
}Stack;
Stack* initStack(int size) {
    if (size <= 0) return NULL;
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (char*)malloc(sizeof(char) * size);
    s->size = size;
    s->top = -1;
    return s;
}
int empty(Stack* s) {
    return s->top == -1;
}
char top(Stack* s) {
    if (s -> top == -1) return -1;
    return s->data[s->top];
}
int push(Stack* s, char val) {
    if (s->top == s->size - 1) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}
int pop(Stack* s) {
    if (s->top == -1) return 0;
    s->top -= 1;
    return 1;
}
void clearStack(Stack* s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}
//void outputStack(Stack* s) {
//    for (int i = s->top; i >= 0; --i) {
//        printf("%d ", s->data[i]);
//    }
//}
#define MAX_OP 15
int solve(char str[]) {
    Stack* s = initStack(200);
    int flag = 1;
    for (int i = 0;str[i];++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(s,str[i]);
        } else {
            switch(str[i]) {
                case ')':
                    if (top(s) == '(') pop(s);
                    else flag = 0;
                break;
                case ']':
                    if (top(s) == '[') pop(s);
                    else flag = 0;
                break;
                case '}':
                    if (top(s) == '{') pop(s);
                    else flag = 0;
                break;
            }
        }
        if (flag == 0) return 0;
    }
    if (!empty(s)) {
        return 0;
    }
    return 1;
}
int main()
{
   // srand(time(NULL));
   // int op = 0, val = 0;
   // Stack* s = initStack(20);
   // for (int i = 0; i < MAX_OP; ++i) {
   //     op = rand() % 2;
   //     switch(op){
   //         case 0:
   //             printf("pop of stack, item = %d\n", top(s));
   //             pop(s);
   //             break;
   //         case 1:
   //         case 2:
   //             val = rand() % 100;
   //             push(s, val);
   //             printf("push of stack, val = %d\n", val);
   //             break;
   //     }
   //     printf("Stack : ");
   //     outputStack(s);
   //     printf("\n\n\n");
   // }
   // clearStack(s);

    char str[100];
    int ret;
    while (~scanf("%s", str)) {
        ret = solve(str);
        if (ret) {
            printf("success\n");
        }
        else {
            printf("failure\n");
        }
    }
    return 0;
}