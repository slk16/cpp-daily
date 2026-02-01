#include <iostream>

using namespace std;

int main()
{
#ifdef DEBUG
    cout << "hello debug" << endl;
#endif // DEBUG

    return 0;
}
