#include <iostream>
#include <memory>
namespace test {

class vector {
public: // rule of file
    vector():m_data(nullptr),m_capacity(0),m_size(0){};
    vector(std::initializer_list<int> il) {
        m_size = il.size();
        m_capacity = get_2power(m_size);
        m_data = std::make_unique<int[]>(m_capacity);   
        size_t n = 0;
        for (auto it = il.begin();it != il.end(); ++it) {
            m_data[n] = *it;
            ++n;            
        }
    }
    vector(vector&& v) noexcept {
        m_data = std::move(v.m_data);
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        v.m_size = 0;
        v.m_capacity = 0;
    }
    vector &operator=(vector &&v) noexcept {
        if (this == &v) 
            return *this;
        m_data = std::move(v.m_data);
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        v.m_size = 0;
        v.m_capacity = 0;
        return *this;
    }
    vector(const vector& v) {
        m_data = std::make_unique<int[]>(v.m_capacity);
        m_capacity = v.m_capacity;
        m_size = v.m_size;
        for (size_t i = 0; i < v.m_size; ++i) {
            m_data[i] = v.m_data[i];
        }
    }
    vector& operator=(const vector& v) {
        if (&v == this)
            return *this;
        m_data = std::make_unique<int[]>(v.m_capacity);
        m_capacity = v.m_capacity;
        m_size = v.m_size;
        for (size_t i = 0; i < v.m_size; ++i) {
            m_data[i] = v.m_data[i];
        }
        return *this;
    }
    ~vector() { }
public: // public method
    size_t size() const noexcept {
        return m_size;
    }
    size_t capacity() const noexcept {
        return m_capacity;
    }
    //void push_back(int val) { // 基本保证
    //    if (m_size == m_capacity) {
    //        size_t new_cap = get_2power(m_capacity);
    //        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(new_cap);
    //        for (size_t i = 0; i < m_size; ++i) {
    //            new_data[i] = m_data[i];
    //        }
    //        m_data = std::move(new_data);
    //        m_capacity = new_cap;
    //    }
    //    m_data[m_size] = val;
    //    ++m_size;
    //}
    

    void push_back(int val) {
    //强异常保证
        if (m_size == m_capacity) {
            size_t new_cap = get_2power(m_size);
            //
            std::unique_ptr<int[]> new_data = std::make_unique<int[]>(new_cap);
            for (size_t n = 0; n < m_size; ++n) {
                new_data[n] = m_data[n];                
            }
            new_data[m_size] = val;
            //
            m_data = std::move(new_data); 
            ++m_size;
            m_capacity = new_cap;
            return ;
        }
        m_data[m_size] = val;
        ++m_size;
    }
    void pop_back() noexcept{
        if (m_size == 0) 
            return ;
        --m_size;
    }
    bool empty() const noexcept {
        return (m_size == 0);
    }
    int& operator[](size_t index)noexcept {
        return m_data[index];
    }
    const int& operator[](size_t index) const noexcept {
        return m_data[index];
    }
    int* begin() {
        return m_data.get();
    }
    int* end() {
        return m_data.get() + m_size;
    }
private:
    size_t get_2power(size_t n) noexcept {
    /* 
    如果不是2的幂，返回大于 $n 的最小2的幂
    如果是2的幂且非0，返回 $n * 2
    如果是0 就返回1
    */
        if (n == 0)
            return 1;
        if ((n & (n - 1)) == 0) {
            return n << 1;
        }
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        n |= (n >> 32);
        return n + 1;
    }
private:
    std::unique_ptr<int[]> m_data;
    size_t m_capacity;
    size_t m_size;
}; // class test::vector

} // namespace test

using namespace test;
void test1() {
    vector v = { 1,2,3,4,5,6};
    std::cout << "v.size() : " << v.size() << std::endl;
    std::cout << "v.capacity() : " << v.capacity() << std::endl;
    v.push_back(17);
    std::cout << "v.size() : " << v.size() << std::endl;
    std::cout << "v.capacity() : " << v.capacity() << std::endl;
    v.push_back(18);
    std::cout << "v.size() : " << v.size() << std::endl;
    std::cout << "v.capacity() : " << v.capacity() << std::endl;
    v.push_back(19);
    std::cout << "v.size() : " << v.size() << std::endl;
    std::cout << "v.capacity() : " << v.capacity() << std::endl;
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }

}
void test2() {
vector v = {1,2,3,4,5,6};
    std::cout << std::endl << "test for range-for" << std::endl;
    for (const auto& i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << "test for move" << std::endl;
vector v1 = std::move(v);
    for (const auto& i: v) {
        std::cout << i << ' ';
    }
    for (const auto& i: v1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << "test for copy" << std::endl;
vector v2 = v1;
    for (const auto& i: v1) {
        std::cout << i << ' ';
    }
    for (const auto& i: v2) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << "test for empty" << std::endl;
    if (v.empty())
        std::cout << "v is empty" << std::endl;        
    else
        std::cout << "v is not empty" << std::endl;
    if (v1.empty())
        std::cout << "v1 is empty" << std::endl;        
    else
        std::cout << "v1 is not empty" << std::endl;
    if (v2.empty())
        std::cout << "v2 is empty" << std::endl;        
    else
        std::cout << "v2 is not empty" << std::endl;
    std::cout << std::endl << "test for push_back" << std::endl;
    v1.push_back(17);
    v1.push_back(18);
    v1.push_back(19);
    for (const auto& i : v1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << "test for pop_back" << std::endl;
    v2.pop_back();
    for (const auto& i : v2) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    v2.pop_back();
    for (const auto& i : v2) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << "test for operator[]" << std::endl;
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
        // std::cout << v2.operator[](i) << " ";
    }
    std::cout << std::endl <<  "test finish" << std::endl;
}
int main() {
    test2();

    return 0;
}