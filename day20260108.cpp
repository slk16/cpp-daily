//#include <iostream>
//
//using namespace std;
//
//class Animal
//{
//public:
//    virtual void speak(){
//        cout << "Animal is speaking." << endl;
//    }
//};
//class Cat:public Animal
//{
//public:
//    void speak(){
//        cout << "Cat is speaking." << endl;
//    }
//};
//void doSpeak(Animal& a){
//    a.speak();
//}
//
//int main(){
//    //cout << "sizeof Animal is " << sizeof(Animal) << endl;
//    //cout << "sizeof Cat is " << sizeof(Cat) << endl;
//
//    Animal a;
//    Cat b;
//    doSpeak(b);
//
//    return 0;
//}
#include <iostream>

using namespace std;
//下面做一个计算器小项目
//
//class Calculator
//{
//private:
//    int m_Num1;
//    int m_Num2;
//public:
//    void set1(int num1){
//        m_Num1 = num1;
//    }
//    void set2(int num2){
//        m_Num2 = num2;
//    }
//    int get1(){
//        return m_Num1;   
//    }
//    int get2(){
//        return m_Num2;   
//    }
//    int getResult(char oper);
//
//};
//int Calculator::getResult(char oper){
//    if (oper == '+'){
//        return m_Num1 + m_Num2;
//    }
//    else if (oper == '-'){
//        return m_Num1 - m_Num2;
//    }
//    else if (oper == '*'){
//        return m_Num1 * m_Num2;
//    }
//    return 0x0FFFffff;
//}
//int main(){
//    Calculator cal;
//    char op;
//    int a;
//    int b;
//    cout << "请输入表达式：" << endl;
//    cin >> a >> op >> b;
//    cal.set1(a);
//    cal.set2(b);
//    cout << "The Result:" << endl; 
//    cout <<a << ' ' << op << ' ' << b << " = " << cal.getResult(op) << endl;
//    return 0;
//}
//

//接下来采用多态来实现
//class AbstractCalculate{
//public:
//    int m_Num1;
//    int m_Num2;
//    virtual int getResult(){
//        return 0x0fffFFFF;
//    }
//    AbstractCalculate(int num1 = 0, int num2 = 0) : m_Num1(num1),m_Num2(num2){}
//};
//class Add: public AbstractCalculate{
//public:
//    virtual int getResult(){
//        return m_Num1 + m_Num2;
//    }
//    Add(){};
////    Add(int num1, int num2){
////        m_Num1 = num1;
////        m_Num2 = num2;
////    }
//    Add(int num1, int num2) : AbstractCalculate(num1,num2){};
//};
//class Minus: public AbstractCalculate{
//public:
//    virtual int getResult(){
//        return m_Num1 - m_Num2;
//    }
//    Minus(int num1 = 0, int num2 = 0) : AbstractCalculate(num1,num2){};
//};
//class Multify: public AbstractCalculate{
//public:
//    virtual int getResult(){
//        return m_Num1 * m_Num2;
//    }
//    Multify(int num1 = 0, int num2 = 0) : AbstractCalculate(num1,num2){};
//};

//int Cumulative(char (&set)[200], int pset){
//    unsigned int weight = 1;
//    unsigned int ret = 0;
//    for (int i = pset;i >= 1;--i) {
//        ret += (set[i - 1] - '0') * weight;
//        weight *= 10;    
//    } 
//    return ret;
//}

//void test(){
//    do 
//    {
//        cout << "Please enter your expression:" << endl;
//        char expression[100] = { 0 };
//        char set1[200] = { 0 };
//        int pset1 = 0;
//        char set2[200] = { 0 };
//        int pset2 = 0;
//        int i = 0;
//        char oper = ' ';
//        cin >> expression;
//        while(expression[i] != '\0'){
//            if(expression[i] == '$'){
  //              goto end;
//            } 
//            else if (expression[i] >= '0' && expression[i] <= '9'){
  //              if (' ' == oper)
  //              {
      //              set1[pset1] = expression[i];
      //              pset1++;
  //              }
  //              else
  //              {
      //              set2[pset2] = expression[i];
      //              pset2++;
  //              }
//            }
//            else if (
  //              expression[i] == '+' ||
  //              expression[i] == '-' ||
  //              expression[i] == '*'
//            )
//            {
  //              oper = expression[i]; 
//            }
//            ++i;
//        } 
//        pset1 = Cumulative(set1, pset1);
//        pset2 = Cumulative(set2, pset2);
//        int ret = 0;
//        if (oper == '+'){
//            Add a(pset1,pset2);
//            ret = a.getResult();
//        }
//        else if (oper == '-'){
//            Minus b(pset1,pset2);
//            ret = b.getResult();
//        }
//        else if (oper == '*'){
//            Multify c(pset1,pset2);
//            ret = c.getResult();
//        }
//        cout << "The result of your expression:" << endl;
////        cout << "num1:" << pset1 << endl;
////        cout << "num2:" << pset2 << endl;
//        cout << ret << endl;
//    }while(true);
//end:
//    return;
//}
////void test2(){
////    Add a(12,34);
////    cout << a.m_Num1 << " " << a.m_Num2 << endl;
////}
////void test3(){
////    char set2[200] = {'1','2'};
////    cout << Cumulative(set2,2) << endl;
////}
//int main(){
//    //test();
//    test();    

//    return 0;
//}

