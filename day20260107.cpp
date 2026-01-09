#include <iostream>

using namespace std;

class Animal{
public:
    void speak();
    

};
void Animal::speak(){
    cout << "动物在说话" << endl;
}

class Cat:public Animal{

public:
    void speak();
};
void Cat::speak(){
    cout << "小猫在说话" << endl;
}
void doSpeak(Animal& a)
{
    a.speak();
}

int main(){
    Cat cat;
    doSpeak(cat);
    

    return 0;
}