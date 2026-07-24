#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>
namespace test{
template <typename T, size_t MinCapacity = 16>
class vector {
public:
    vector() : m_data(nullptr), m_size(0), m_capacity(0) { }
    vector(std::initializer_list<T> il);
    vector<T, MinCapacity>& operator=(std::initializer_list<T> il);
    vector(const vector<T, MinCapacity>& other);
    vector<T, MinCapacity>& operator=(const vector<T, MinCapacity>& other);
    vector(vector<T, MinCapacity>&& other) noexcept ;
    vector<T, MinCapacity>& operator=(vector<T, MinCapacity>&& other) noexcept ;
    ~vector(){};
public:
    void push_back(T val);
    void pop_back() noexcept ;
    template <typename... Args>
    void emplace_back(Args&&... args) ;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    T* begin() const noexcept;
    T* end() const noexcept;
private:
    inline size_t get_2power(size_t n) const noexcept;
private:
    std::unique_ptr<T[]> m_data;
    size_t m_size;
    size_t m_capacity;
};

template <typename T, size_t MinCapacity>
vector<T, MinCapacity>::vector(std::initializer_list<T> il) {
    size_t new_cap = get_2power(il.size());
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_cap);
    size_t i = 0;
    for (auto it = il.begin(); it != il.end(); ++it) {
        new_data[i] = *it;
        ++i;
    }
    m_data = std::move(new_data);
    m_size = il.size();
    m_capacity = new_cap;
}

template <typename T, size_t MinCapacity>
vector<T, MinCapacity>& vector<T, MinCapacity>::operator=(std::initializer_list<T> il) {
    size_t new_cap = get_2power(il.size());
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_cap);
    size_t i = 0;
    for (auto it = il.begin(); it != il.end(); ++it) {
        new_data[i] = *it;        
        ++i;
    }
    m_data = std::move(new_data);
    m_capacity = new_cap;
    m_size = il.size();
    return *this;
}

template <typename T, size_t MinCapacity>
void vector<T, MinCapacity>::push_back(T val) {
    if (m_size == m_capacity) {
        size_t new_cap = get_2power(m_size);
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_cap);
        size_t i = 0;
        while (i < m_size) {
            new_data[i] = std::move(m_data[i]);
            ++i;
        }
        new_data[m_size] = val;
        m_data = std::move(new_data);
        ++m_size;
        m_capacity = new_cap;
        return ;
    }
    m_data[m_size] = val;
    ++m_size;
}

template <typename T, size_t MinCapacity>
template <typename... Args>
void vector<T, MinCapacity>::emplace_back(Args&&... args) {
    if (m_size == m_capacity) {
        size_t new_cap = get_2power(m_size);
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_cap);
        size_t i = 0;
        while (i < m_size) {
            new (&new_data[i]) T(std::move(m_data[i]));
            ++i;
        }
        new (&new_data[m_size]) T(std::forward<Args>(args)...);
        m_data = std::move(new_data);
        m_capacity = new_cap;
    } else {
        new(&m_data[m_size]) T(std::forward<Args>(args)...);
    }
    ++m_size;
}


template <typename T, size_t MinCapacity>
void vector<T, MinCapacity>::pop_back() noexcept {
    --m_size;
}

template <typename T, size_t MinCapacity>
size_t vector<T, MinCapacity>::size() const noexcept {
    return this->m_size;
}

template <typename T, size_t MinCapacity>
size_t vector<T, MinCapacity>::capacity() const noexcept {
    return this->m_capacity;
}

template <typename T, size_t MinCapacity>
T* vector<T, MinCapacity>::begin() const noexcept{
    return m_data.get();
}

template <typename T, size_t MinCapacity>
T* vector<T, MinCapacity>::end() const noexcept{
    return (m_data.get() + m_size);
}

template <typename T, size_t MinCapacity>
vector<T, MinCapacity>::vector(const vector<T, MinCapacity>& other) {
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(other.m_capacity);
    for (size_t i = 0; i < other.m_size; ++i) {
        new_data[i] = other.m_data[i];
    }
    m_data = std::move(new_data);
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

template <typename T, size_t MinCapacity>
vector<T, MinCapacity>& vector<T, MinCapacity>::operator=(const vector<T, MinCapacity>& other) {
    if (&other == this)
        return *this;
    std::unique_ptr<T[]> new_data = nullptr;
    new_data = std::make_unique<T[]>(other.m_capacity);
    for(size_t i = 0; i < other.size(); ++i) {
        new_data[i] = other.m_data[i];
    }
    m_data = std::move(new_data);
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    return *this;
}

template <typename T, size_t MinCapacity>
vector<T, MinCapacity>::vector(vector&& other) noexcept {
    m_data = std::move(other.m_data);    
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_size = 0;
    other.m_capacity = 0;
}

template <typename T, size_t MinCapacity>
vector<T, MinCapacity>& vector<T, MinCapacity>::operator=(vector&& other) noexcept {
    if (this == &other)
        return *this;
    m_data = std::move(other.m_data);
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_size = 0;
    other.m_capacity = 0;
    return *this;
}

template <typename T, size_t MinCapacity>
inline size_t vector<T, MinCapacity>::get_2power(size_t n) const noexcept {
    if (n == 0)
        return MinCapacity;
    size_t ret = 0;
    if (0 == (n & (n - 1)))
        ret = n << 1;
    else {
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        n |= (n >> 32);
        ret = n + 1;        
    }
    return (ret > MinCapacity ? ret : MinCapacity);
}

template <>
class vector<bool, 4> {
public:
    vector(){};
    vector(std::initializer_list<bool> il);
    vector<bool,4>& operator=(std::initializer_list<bool> il);
    vector(const vector<bool,4>& other);
    vector<bool,4>& operator=(const vector<bool,4>& other);
    vector(vector<bool,4>&& other) noexcept ;
    vector<bool,4>& operator=(vector<bool,4>&& other) noexcept ; 
    ~vector(){};
public:
    size_t size() const noexcept;
    size_t capacity() const noexcept;
private:
    size_t get_2power(size_t n) const noexcept;
    size_t get_cap(size_t n) const noexcept; 
private:
private:
    std::unique_ptr<uint64_t[]> m_data = nullptr;
    uint64_t m_count = 0; // 存储多少位
    size_t m_size = 0; // 被使用的uint64_t的个数
    size_t m_capacity = 0; // uint64_t变量的个数
};

size_t
vector<bool,4>::get_2power(size_t n) const noexcept {
    if (n == 0)
        return 4;
    size_t ret;
    if (0 == (n & (n - 1)))
        ret = n << 1;
    else {
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        n |= (n >> 32);
        ret = n + 1;
    }
    return (ret > 4 ? ret : 4);
}

size_t
vector<bool,4>::get_cap(size_t n) const noexcept{ // $n 存储bool位数
    size_t new_cap = ((n + 63) >> 6);
    new_cap = get_2power(new_cap);
    return new_cap;
}

vector<bool,4>::vector(std::initializer_list<bool> il) {

}

vector<bool,4>& 
vector<bool,4>::operator=(std::initializer_list<bool> il) {
    size_t new_cap = get_cap(il.size());
    
    return *this;
}

vector<bool,4>::vector(const vector<bool,4>& other) {
    std::unique_ptr<uint64_t[]> new_data = std::make_unique<uint64_t[]>(other.m_capacity);
    size_t i =0;
    while(i < other.m_size) {
        new_data[i] = other.m_data[i];
        ++i;
    }
    m_data = std::move(new_data); 
    m_count = other.m_count;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

vector<bool,4>&
vector<bool,4>::operator=(const vector<bool,4>& other) {
    if (this == &other)
        return *this;
    std::unique_ptr<uint64_t[]>new_data = std::make_unique<uint64_t[]>(other.m_capacity);
    size_t i = 0;
    while(i < other.m_size) {
        new_data[i] = other.m_data[i];
        ++i;
    }
    m_data = std::move(new_data);
    m_count = other.m_count;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    return *this;
}

vector<bool,4>::vector(vector<bool,4>&& other) noexcept{
    m_data = std::move(other.m_data); 
    m_count = other.m_count;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_count = 0;
    other.m_size = 0;
    other.m_capacity = 0;
}

vector<bool,4>&
vector<bool,4>::operator=(vector<bool,4>&& other) noexcept {
    if (this == &other)
        return *this;
    m_data = std::move(other.m_data);
    m_count = other.m_count;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_count = 0;
    other.m_size = 0;
    other.m_capacity = 0;
    return *this;
}




void test01() {
    vector<int> v1 = { 1,2,3,4,5,6};
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for MinCapacity" << std::endl;
    std::cout << "v1.capacity : " << v1.capacity() << std::endl;
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for range-for" << std::endl;
    for (auto& i : v1) {
        std::cout << i << "  ";
    }
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for copy" << std::endl;
    vector<int> v2;
    v2 = v1;
    std::cout << "v2 : ";
    for (auto& i : v2) {
        std::cout << i << "  ";
    }
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for move" << std::endl;
    vector<int> v3 = { 1, 2, 3};
    v3 = std::move(v1);
    std::cout << "v1 : ";
    for (auto& i : v1) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    std::cout << "v3 : ";
    for (auto& i : v3) {
        std::cout << i << "  ";
    }
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for operator=(std::initializer ...)" << std::endl;
    v1 = { 5, 4, 3, 2, 1};
    for (auto& i : v1) {
        std::cout << i << "  ";
    }
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for some method" << std::endl;
    std::cout << "v1.size() : " << v1.size() << std::endl;
    std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
    std::cout << "v1.begin() : " << v1.begin() << std::endl;
    std::cout << "v1.end() : " << v1.end() << std::endl;

    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for construct by copy" << std::endl;
    vector<int> v4 = v3;
    std::cout << "v4 : ";
    for (const auto& i : v4) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    std::cout << "v3 : ";
    for (const auto& i : v3) {
        std::cout << i << "  ";
    }

    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for construct by move" << std::endl;
    vector<int> v5 = std::move(v3);
    std::cout << "v5 : ";
    for (const auto& i : v5) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    std::cout << "v3 : ";
    for (const auto& i : v3) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for push_back(),pop_back()" << std::endl;
    v1 = v5;
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    std::cout << "v1 : ";
    for (const auto& i : v1) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    std::cout << "v1 : ";
    v1.pop_back();
    v1.pop_back();
    for (const auto& i : v1) {
        std::cout << i << "  ";
    }
}

void test02() {
    using test::vector;
    vector<int> v1,v2;
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for push_back"<< std::endl;
    for (int i = 0; i < 40; ++i) {
        v1.push_back(i + 1);
    }    
    std::cout << "v1 : ";
    for (const auto& a : v1) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << "v1.size() : " << v1.size() << std::endl;
    std::cout << "v1.capacity() : " << v1.capacity() << std::endl;
    std::cout << std::endl << "------------------------------------" << std::endl;
    std::cout << "test for emplace_back"<< std::endl;
    for (int i = 0; i < 40; ++i) {
        v2.emplace_back(i + 1);        
    }
    std::cout << "v2 : ";
    for (const auto& a : v2) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << "v2.size() : " << v2.size() << std::endl;
    std::cout << "v2.capacity() : " << v2.capacity() << std::endl;

}

} // namespace test

int main() {
    test::test02();



    return 0;
}