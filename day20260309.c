#include <stdio.h>

int main() {
    char str[10] = {
        0
    };
    char a;
    int top = 0;
    while ('\n' != (a = getchar())) {
        str[top] = a;
        ++top;
    }
    for (; top > 0;) {
        --top;
        printf("%c", str[top]);
    }


    return 0;
}
