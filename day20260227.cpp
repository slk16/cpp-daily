
//#include <iostream>
//#include <unistd.h>
//using namespace std;
//
//#define REGS_FOREACH(_) _(X) _(Y)
//#define OUTS_FOREACH(_) _(A) _(B) _(C) _(D) _(E) _(F)
//#define RUN_LOGIC X1 = !X && Y; \
//            Y1 = !X && !Y;
//#define DEFINE(X) static int X, X##1;
//#define UPDATE(X) X = X##1;
//#define PRINT(X) cout << #X << " = " << X << endl;
//
//int main()
//{
//    REGS_FOREACH(DEFINE);
//    while(1)
//    {
//        RUN_LOGIC;
//        REGS_FOREACH(PRINT);
//        REGS_FOREACH(UPDATE);
//        putchar('\n');
//        fflush(stdout);
//        sleep(1);
//    }
//    return 0;
//}
#include <iostream>


void hanno(int n, char from, char to, char via)
{
    if (n == 1)
    {
        std::cout << from << " -> " << to << std::endl;
        return;
    }
    hanno(n - 1,from,via,to);
    hanno(1,from,to,via);
    hanno(n - 1,via,to,from);
    return;
}
typedef struct {
    int pc, n;
    char from, to, via;
}Frame;

#define call(...) ()

int main()
{
    hanno(2,'a','c','b');



    return 0;
}