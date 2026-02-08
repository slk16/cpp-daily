#include <iostream>
#include <termios.h> 
#include <unistd.h>

using namespace std;
#define width 12
#define length 12
termios* create(void)
{
    termios* original = new termios;
    tcgetattr(STDIN_FILENO,original);

    struct termios modified = *original;
    modified.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    modified.c_oflag &= ~(OPOST);
    modified.c_cflag |= ~(CS8);
    modified.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    modified.c_cc[VMIN] = 0;
    modified.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO,TCSAFLUSH,&modified);

    return original;
}
void show(int arr[width][length]){
    for(int i = 0; i < width; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
        }
        cout << endl;
    }

}
int main()
{
    int arr[width][length] = { 0 };
    int hx,hy,tx,ty;
    do 
    {
        system("clear");
        show(arr);

    }while();


    return 0;
}