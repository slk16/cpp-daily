#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream fs;
   
    ifstream ifs;
    //ofs.open("C:\\Users\\pc\\Desktop\\test.txt",ios::out | ios::app);

    //ofs << "Hello C++ file operator" << endl; 
    
    //ofs << "Hello world again";

    //ofs.close();

    //读文件 

    string t;
    char arr[40] = { 0 };

    ifs.open("C:\\Users\\pc\\Desktop\\test.txt", ios::in);

 
    ifs >> arr;
    
    
    cout << arr << endl;


    return 0;
}