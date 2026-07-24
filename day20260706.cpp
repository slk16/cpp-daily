#include <iostream>
#include <vector>
#include <initializer_list>
namespace test {
int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("division by zero!");
    }
    return a / b;
}
void test1() {
    int a = 10, b = 0;
    try {
        divide(a,b);
    } catch (std::runtime_error& e) {
        std::cout << "runtime_error : " << e.what() << std::endl; 
    }
}
void test_logic_error() {
    std::cout << "throw logic_error" << std::endl;
    throw std::logic_error("logic_error");
}
void test_runtime_error() {
    std::cout << "throw runtime_error" << std::endl;
    throw std::runtime_error("runtime_error");
}
void test_bad_alloc() {
    std::cout << "throw bad_alloc" << std::endl;
    throw std::bad_alloc();
}
void test2() {
    try {
        test_logic_error();
        test_runtime_error();
        test_bad_alloc();
    } catch(std::exception& e) {
        std::cout << "exception! : " << e.what() << std::endl;
    }
}
void test_throw_int() {
    std::cout << "throw int" << std::endl;
    throw 5;
}
void test3() {
    try {
        test_throw_int();
    } catch( ... ) {
        std::cout << "exception ? " << std::endl;
    }

}
class Tracer {
public:
    ~Tracer() {
        std::cout << "Tracer destructor called" << std::endl;
    }

private:
};
void test4() {
    try {
        Tracer t;
        divide(10,0);
    } catch(std::runtime_error& re) {
        std::cout << "exception! : " << re.what();
    }
}
class Resource {
public:
    Resource() {};
    Resource(std::string type):m_type(type){
        std::cout << "Resource(" << m_type << ") allocate." << std::endl;
    }
    ~Resource() {
        std::cout << "Resource(" << m_type <<") free." << std::endl;
    }
private:
    std::string m_type = "none";
};
Resource* connect() {
    if (false) {
        throw std::runtime_error("connect failed!!!");
    }
    Resource* ret = new Resource("net"); 
    std::cout << "connect established" << std::endl;
    return ret;
}

Resource* open_file() {
    if (!false) {
        throw std::runtime_error("open_file failed!!!");
    }
    Resource* ret = new Resource("file");
    return ret;
}
class Database {
public:
    Database(){
        try {
            connect();
            open_file();
        } catch(std::runtime_error& re) {
            std::cout << re.what() << std::endl;
        }
    }
    ~Database(){
        if (net != nullptr)
            delete net;
        if (file != nullptr)
            delete file;
    }
private:
    Resource* net = nullptr;
    Resource* file = nullptr;
};
void test5() {
    Database db;
}

class foo {
public:
    ~foo() {
        std::cout << "foo deconstructor called" << std::endl;
        //throw std::runtime_error("deconstrucion_error");
    }
};
void test6() {
    try {
        foo bar;
    } catch (std::runtime_error& re) {
        std::cout << "Exception! : " << re.what() << std::endl;
    }
}
class vector {
public:
    vector():data(nullptr),capacity(0u),size(0u) {};
    vector(std::initializer_list<int> il) {
        if (data == nullptr) {
            throw std::runtime_error("vector failed to initialize");
        }
        size_t n = 0;
        for (int val : il) {
            data[n++] = val;
        }
    } 
    void push_back() {

    }
private:
    int* data = nullptr;
    size_t capacity = 0;
    size_t size = 0;
};
void test7() {
    vector v = {1,2,3,4,5};
}
} // namespace test
int main() {





//    std::vector<int> v;
//    v = { 1,2,3,4,5,6};
//    for (const auto& i : v) {
//        std::cout << i << " ";
//    }

    return 0;
}