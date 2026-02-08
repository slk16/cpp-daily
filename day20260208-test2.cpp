#include <iostream>
#include <termios.h>
#include "headfile/tc.h"

using namespace std;

int main()
{
    cout << TC_RED << "hello world" << TC_NRM << endl;
    // cout << TC_0_RED << "hello world" << TC_NRM << endl;
    cout << TC_CYN << "Hello world!" << TC_NRM << endl;

    cout << TC_MAG << "Hello world!" << TC_NRM << endl;

    cout << TC_WHT << "Hello world!" << TC_NRM << endl;

    return 0;
}