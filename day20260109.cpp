#include <iostream>

using namespace std;

int main(){
//    int a = 1;
//    int b = 2 + a++ + a++;
//    cout << b << endl;//predict: 5
//
//    a = 1;
//    b = 2 + ++a + ++a;
//    cout << b << endl;//predict: 7 
//
    

    return 0;
}
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")
void init();
int main()
{
    SOCKET s_server = socket(AF_INET,SOCK_STREAM,0);

    return 0;
}
void init() {

}

#include <iostream>

using namespace std;

class Base
{
public:
    virtual void func1() = 0;
    virtual void func2() = 0;

};
class Derived:public Base
{
public:
    virtual void func1(){// 必须对基类纯虚函数进行重写
        cout << "Derived output 1" << endl;
    }
    virtual void func2(){// 如果有多个纯虚函数，必须对每一个都进行重写
        cout << "Derived output 2" << endl;
    }
};

int main(){
    Derived d;
    d.func1();

    return 0;
}

#include <iostream>

using namespace std;

class AbstractDrink 
{
public:
    virtual void boil() = 0;// 注水

    virtual void brew() = 0;// 冲泡

    virtual void pour() = 0;// 倒入杯中

    virtual void put() = 0;// 加入辅料

    void makeDrink(){
        boil();
        brew();
        pour();
        put();
    }
};
class Coffee: public AbstractDrink 
{
public:
    virtual void boil(){
        cout << "注水" << endl;
    }
    virtual void brew(){
        cout << "冲泡咖啡" << endl;
    }
    virtual void pour(){
        cout << "倒入杯中" << endl;
    }
    virtual void put(){
        cout << "加入糖和牛奶" << endl;
    }
};
class Tea: public AbstractDrink
{
public:
    virtual void boil(){
        cout << "注水" << endl;
    }
    virtual void brew(){
        cout << "冲泡茶叶" << endl;
    }
    virtual void pour(){
        cout << "倒入杯中" << endl;
    }
    virtual void put(){
        cout << "加入枸杞" << endl;
    }
};
void make(AbstractDrink* ad){
    ad->makeDrink();
    delete ad;
}

int main(){
    make(new Coffee);
    cout << "---------------" << endl;
    make(new Tea);

    return 0;
}

 虚析构和纯虚析构

#include <iostream>

using namespace std;
class Animal
{
public:
    virtual void speak() = 0;
    Animal(){
        cout << "Animal constructor invocation" << endl;
    }
//    virtual ~Animal(){
//        cout << "Animal destructor invocation" << endl;
//    }
    virtual ~Animal() = 0;

};
Animal::~Animal(){
    cout << "Animal destructor invocation" << endl;
}

class Cat: public Animal
{
public:
    Cat(string name){
        cout << "Cat constructor invocation" << endl;
        m_name = new string;
        *m_name = name;
    }
    virtual void speak(){
      
        cout << *m_name << "小猫在说话" << endl;
    }
    string* m_name;
    ~Cat(){
        cout << "Cat destructor invocation" << endl;
        if (m_name != NULL){
            delete m_name;
            m_name = NULL;
        }
    }
};

int main(){
    Animal* a = new Cat("Tom"); 
    a->speak();
    delete a;

    return 0;
}

//做一个案例：电脑组装
#include <iostream>

using namespace std;

class Cpu
{
public:
    virtual void calculate() = 0;

};
class IntelCpu: public Cpu
{
public:
    void calculate(){
        cout << "Intel cpu is calculating." << endl;
    }
};
class AmdCpu: public Cpu
{
public:
    void calculate(){
        cout << "AMD cpu is calculating." << endl;
    }
};
//显卡
class GraphicsCard
{
public:
    virtual void display() = 0;
};
class IntelGraphicsCard: public GraphicsCard
{
public:
    virtual void display(){
        cout << "Intel show" << endl;
    }
};
class AmdGraphicsCard: public GraphicsCard
{
public:
    virtual void display(){
        cout << "Amd show" << endl;
    }
};

//内存
class Memory
{
public:
    virtual void storage() = 0; 
};
class IntelMemory: public Memory
{
public:
    virtual void storage(){
        cout << "Intel memory start" << endl;
    }
};
class AmdMemory: public Memory
{
public:
    virtual void storage(){
        cout << "Amd memory start" << endl;
    }
};
// 组装电脑
class Computer
{
public:
    Cpu* m_c;
    GraphicsCard* m_gc;
    Memory* m_m; 
    Computer(Cpu* c, GraphicsCard* gc, Memory* m)
    {
        m_c = c;
        m_gc = gc;
        m_m = m; 
    }
    void work(){
        m_c->calculate();
        m_gc->display();
        m_m->storage();
    }
    ~Computer(){
        if (m_c != NULL)
        {
            delete m_c;
            m_c = NULL;
        }
        if (m_gc != NULL)
        {
            delete m_gc;
            m_gc = NULL;
        }
        
        if (m_m != NULL)
        {
            delete m_m;
            m_m = NULL;
        }
        
    }
};

//下面是一个回文数算法
#include <math.h>
bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    else if (x <= 9 && x>= 0)
    {
        return true;
    }
    else if (x % 10 == 0)
    {
        return false;
    }
    else{
        int bit = 1; 
        int temp = x;
        while (temp >= 10){
            temp /= 10;
            ++bit;
        }
        int a = 0;
        int b = 0;
        while(a == b && bit > 1){
            a = x % 10;
            temp = (int)pow(10,bit-1);
            b = x / temp;
            if ((x < temp) && (a != 0)){
                return false;
            }
            x = (x - b*temp) / 10;
            bit-=2;
        }
        if (a == b && x < 10){
            return true;
        }
        else
        {
            return false;
        }
    }
}
void my_delete(Computer* &computer){
    if (computer != NULL){
        delete computer;
        computer = NULL;
    }
}

int main(){
    // test 1
    //isPalindrome(121);
    cout << "test 1" << endl;
    Cpu* c1 = new IntelCpu;
    GraphicsCard* a1 = new AmdGraphicsCard;
    Memory* m1 = new IntelMemory;
    Computer* computer1 = new Computer(c1,a1,m1);
    computer1->work();
    delete computer1;
    computer1 = NULL;

    // test 2
    cout << "test 2" << endl;
    Cpu* c2 = new AmdCpu;
    GraphicsCard* a2 = new AmdGraphicsCard;
    Memory* m2 = new IntelMemory;
    Computer* computer2 = new Computer(c2,a2,m2);
    computer2->work();
    delete computer2;
    computer2 = NULL;
    
    // test 3
//    cout << "test 3" << endl;
//    Cpu* c3 = new IntelCpu;
//    GraphicsCard* a3 = new IntelGraphicsCard;
//    Memory* m3 = new AmdMemory;
//    Computer* computer3 = new Computer(c3,a3,m3);
//    computer3->work();
//    delete computer3;
//    computer3 = NULL;

    cout << "test 3" << endl;
    Computer* computer3 = new Computer(new IntelCpu,new IntelGraphicsCard,new AmdMemory);
    computer3->work();
    my_delete(computer3);




    
    return 0;
}

//文件操作

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    
    return 0;
}