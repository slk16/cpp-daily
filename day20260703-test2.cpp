#include <iostream>
namespace slk{
template <typename T>
class my_uptr {
public:
    explicit my_uptr(T* ptr) {
        m_p = ptr;
    };
    my_uptr(my_uptr<T>&& ptr) {
        m_p = ptr.m_p;   
        ptr.m_p = nullptr;
    }
    my_uptr(my_uptr<T>& ptr) = delete;
    my_uptr& operator=(my_uptr<T>& ptr) = delete;
    my_uptr& operator=(my_uptr<T>&& ptr) {
        if (ptr.m_p == m_p)
            return *this;
        if (ptr.m_p == nullptr)
            return *this;
        delete m_p;
        m_p = ptr.m_p;
        ptr.m_p = nullptr;
        return *this;
    }
    bool operator==(my_uptr<T>&& ptr) {
        if (ptr.m_p == this->m_p)
            return true;
        else
            return false;
    }
    T& operator*() {
        return *m_p;
    }
    T* operator->() {
        return m_p;
    }
    explicit operator bool() {
        if (m_p != nullptr)
            return true;
        else
            return false;
    }
    T* get() {
        return m_p;
    }
    T* release() {
        T* ret = m_p;
        m_p = nullptr;
        return ret;
    }
    void reset() {
        if (m_p != nullptr)
            delete m_p;
        m_p = nullptr;
    }
    ~my_uptr() {
        if (m_p != nullptr)
            delete m_p;
    }
private:
    T* m_p;
};
} // namespace slk;
using slk::my_uptr;

int main() {
    // 测试1: 基本构造和解引用
    std::cout << "=== test1: construct and dereference ===" << std::endl;
    my_uptr<int> p1(new int(42));
    std::cout << "p1 bool: " << static_cast<bool>(p1) << " (expect 1)" << std::endl;
    std::cout << "*p1: " << *p1 << " (expect 42)" << std::endl;

    // 测试2: 移动构造
    std::cout << "=== test2: move constructor ===" << std::endl;
    my_uptr<int> p2(std::move(p1));
    std::cout << "p1 bool: " << static_cast<bool>(p1) << " (expect 0)" << std::endl;
    std::cout << "p2 bool: " << static_cast<bool>(p2) << " (expect 1)" << std::endl;
    std::cout << "*p2: " << *p2 << " (expect 42)" << std::endl;

    // 测试3: 移动赋值
    std::cout << "=== test3: move assignment ===" << std::endl;
    my_uptr<int> p3(new int(100));
    p3 = std::move(p2);
    std::cout << "p2 bool: " << static_cast<bool>(p2) << " (expect 0)" << std::endl;
    std::cout << "p3 bool: " << static_cast<bool>(p3) << " (expect 1)" << std::endl;
    std::cout << "*p3: " << *p3 << " (expect 42)" << std::endl;

    // 测试4: release
    std::cout << "=== test4: release ===" << std::endl;
    my_uptr<int> p4(new int(7));
    int* raw = p4.release();
    std::cout << "p4 bool: " << static_cast<bool>(p4) << " (expect 0)" << std::endl;
    std::cout << "*raw: " << *raw << " (expect 7)" << std::endl;
    delete raw; // release后自己负责释放

    // 测试5: reset
    std::cout << "=== test5: reset ===" << std::endl;
    my_uptr<int> p5(new int(99));
    p5.reset();
    std::cout << "p5 bool: " << static_cast<bool>(p5) << " (expect 0)" << std::endl;

    // 测试6: 空指针reset不崩溃
    std::cout << "=== test6: reset on empty ===" << std::endl;
    my_uptr<int> p6(new int(1));
    int* r = p6.release();
    delete r;
    p6.reset();  // m_p已经是nullptr，reset不崩溃
    std::cout << "no crash (expect ok)" << std::endl;

    // 测试7: 自赋值不崩溃
    std::cout << "=== test7: self move-assignment ===" << std::endl;
    my_uptr<int> p7(new int(55));
    p7 = std::move(p7);
    std::cout << "p7 bool: " << static_cast<bool>(p7) << " (expect 1)" << std::endl;
    std::cout << "*p7: " << *p7 << " (expect 55)" << std::endl;

    return 0;
}