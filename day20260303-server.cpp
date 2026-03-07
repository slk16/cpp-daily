#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> // 引入close()函数
using namespace std;

class createsocket_error:public exception
{
public:
    const char* what() const noexcept   //等价于const throw() 
    {
        return "Failed to create socket";
    }
};
int createSocket(){
    try {
        int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        if (sockfd == -2)
        {
            throw createsocket_error();
        }
        return sockfd;
    } catch(createsocket_error c){
        cerr << c.what() << endl;
        //throw catch中使用throw将异常向上层传递


        return -1;
    }
    //有多重异常处理方式  1、直接在catch中重新抛出异常  2、返回错误码  3、在try中抛出异常后，再返回错误码

}

int main()
{
    int sockfd = createSocket();
    sockaddr sa;

    bind(sockfd,)





    return 0;
}