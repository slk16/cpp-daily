#include <iostream>
#include <memory>
// 学习shared_ptr的用法及原理
void test1(std::shared_ptr<int>& sp) {
    std::cout << "use_count : " << sp.use_count() << std::endl;
}
void test2(std::shared_ptr<int> sp) {
    std::cout << "use_count : " << sp.use_count() << std::endl;
}
void test3() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(5);
    auto sp2 = sp1;
    std::cout << "use_count : " << sp2.use_count() << std::endl;
    sp2.reset(); 
    std::cout << "sp1.use_count : " << sp1.use_count() << std::endl;
    std::cout << "sp2.use_count : " << sp2.use_count() << std::endl;
}
void test4() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(10);
    auto sp2 = sp1;
    auto sp3 = sp2;
    std::cout << "sp1.use_count : " << sp1.use_count() << std::endl;
    sp2.reset();
    std::cout << "sp1.use_count : " << sp1.use_count() << std::endl;
    sp3.reset();
    std::cout << "sp1.use_count : " << sp1.use_count() << std::endl;
    sp3.reset();
    std::cout << "No error" << std::endl;
}
void test5() {
    std::shared_ptr<int> sp1(new int(5));
    sp1.reset();
}
void test6() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(5);
    std::cout << "use_count() : " << sp1.use_count() << std::endl;// 1
    std::weak_ptr wp = sp1;
    std::cout << "use_count() : " << sp1.use_count() << std::endl;// 1
    // std::cout << "*wp : " << *wp << std::endl; // error
    if (wp.expired() != true)
        std::cout << "wp's owner : " << *wp.lock() << std::endl; 
    std::cout << "use_count() : " << sp1.use_count() << std::endl;// 1
    auto sp2 = sp1;
    sp1.reset();
    if (wp.expired()) {
        std::cout << "sp1 is deleted" << std::endl;
    } else {
        std::cout << "sp1 is not deleted" << std::endl;
    }
    sp2.reset();
    if (wp.expired()) {
        std::cout << "sp1 is deleted" << std::endl;
    } else {
        std::cout << "sp1 is not deleted" << std::endl;
    }
}

void test7() {
    class Node {
    public:
        Node(std::string name) {
            m_name = name;
            std::cout << m_name << " Constructor called" << std::endl;
        }
        Node(std::string name, std::shared_ptr<Node> next) {
            m_name = name;
            m_next = next;
            std::cout << m_name << " -> " << next->m_name << " Constructor called" << std::endl;
        }
        ~Node() {
            std::cout << m_name << " Deconstructor called" << std::endl;
        }
        std::string m_name;
        std::shared_ptr<Node> m_next;
        std::weak_ptr<Node> m_prev;
    };
    std::shared_ptr<Node> sp1 = std::make_shared<Node> ("Node1");
    std::shared_ptr<Node> sp2 = std::make_shared<Node> ("Node2");
    sp1->m_next = sp2;
    sp2->m_prev = sp1;
    std::cout << "sp1.use_count() : " << sp1.use_count() << std::endl;
    std::cout << "sp2.use_count() : " << sp2.use_count() << std::endl;
    
}
int main() {








    //std::cout << "use_count : " << sp1.use_count() << std::endl;
    //auto sp2 = sp1;
    //std::cout << "use_count : " << sp2.use_count() << std::endl;
    //auto sp3 = sp2;
    //std::cout << "use_count : " << sp3.use_count() << std::endl;

    //std::cout << "use_count : " << sp1.use_count() << std::endl;
    //test1(sp1);
    //std::cout << "use_count : " << sp1.use_count() << std::endl;

    

    return 0;
}