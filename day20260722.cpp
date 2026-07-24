#include <iostream>
#include <forward_list>
#include <list>


namespace test {
    namespace v1 {
        void test01() {
            std::list<int> lt1 = { 1,3,5,7 };
            std::list<int> lt2 = { 2,4,6,8 };
            auto print = [](std::list<int> &lt) {
                for (const auto &trans : lt) {
                    std::cout << trans <<  " ";
                }
            };
            auto print_both = [&]() {
                std::cout << "lt1 : ";
                print(lt1);
                std::cout << std::endl;
                std::cout << "lt2 : ";
                print(lt2);
                std::cout << std::endl;
            };
            std::cout << "merge" << std::endl;
            lt1.merge(lt2);
            print_both();
            {
                std::cout << "copy" << std::endl;
                std::list<int> temp = {11,13,15,17,1,2,3,4,5 };
                lt2 = temp;
            }

            std::cout << "splice" << std::endl;
            lt1.splice(++lt2.cbegin(), lt1);
            print_both();
            
            std::cout << "sort" << std::endl;
            lt2.sort();
            print_both();

            std::cout << "unique" << std::endl;
            lt2.unique();
            print_both();

            std::cout << "remove_if" << std::endl;
            lt2.remove_if([](int val) -> bool {
                if (val >= 4 && val <= 5)
                    return true;
                else
                    return false;
            });
            print_both();
            
            std::cout << "reverse" << std::endl;
            lt2.reverse();
            print_both();
            
        }

    } // namespace v1
      
    namespace v2 {
        // forward_list
        
        template <typename T>
        struct Node {
            struct Node* next;
            T data;
        public:
            Node():next(nullptr), data(T()) {}
            Node(const T& val) : next(nullptr), data(val) {}
            Node(T&& val) : next(nullptr), data(std::move(val)) {}
            Node(const Node& other) = default;
            Node& operator=(const Node& other) = default;
            Node(Node&& other) : next(nullptr), data(std::move(other.data)) {}
            Node& operator=(Node&& other) {
                if (this == &other)
                    return *this;
                data = std::move(other.data);
                next = nullptr;
                return *this;
            }
            ~Node() = default;
        };
        
        template <typename T>
        class iterator {
        public:
            iterator()noexcept : it(nullptr) {};
            iterator(Node<T>* ptr) noexcept : it(ptr) {};
            iterator(const iterator& other) noexcept : it(other.it) {}
            iterator& operator=(const iterator& other) noexcept { it = other.it; return *this;}
            iterator(iterator&& other) noexcept { it = other.it; other.it = nullptr; };
            iterator& operator=(iterator&& other) noexcept { it = other.it; other.it = nullptr; return *this;}
        public:
            using iterator_category = std::forward_iterator_tag;
            using pointer = Node<T>*;
            using reference = T&;
            using difference_type = ptrdiff_t;
            using value_type = Node<T>;
        public:
            T& operator*() const noexcept {
                return it->data;
            }
            Node<T>* operator->() const noexcept {
                return it;
            }
            iterator operator++(int) {
                iterator temp = *this; 
                it = it->next;
                return temp;
            }
            iterator& operator++() {
                it = it->next;
                return *this;
            }
            bool operator==(const iterator& other) const {
                return other.it == it;
            }
            bool operator!=(const iterator& other) const {
                return other.it != it;    
            }
            operator bool() const {
                return (bool)it;
            }
        private:
            Node<T>* it;
        };

        template <typename T>
        class forward_list {
        public:
            forward_list(){};
            forward_list(const forward_list<T>& other);
            forward_list& operator=(const forward_list<T>& other);
            forward_list(forward_list<T>&& other);
            forward_list<T>& operator=(forward_list<T>&& other);
            ~forward_list();
        public:
            forward_list(std::initializer_list<T> il);
            forward_list<T>& operator=(std::initializer_list<T> lt);
        public:
            void push_front(const T& data);
            iterator<T> insert_after(iterator<T> it, const T& data);
            iterator<T> before_begin() noexcept ;
            iterator<T> begin();
            iterator<T> end();
            void release();
        private:
            template<typename... Args>
            static Node<T>* get_node(Args&&... args);
            static Node<T>* copy(const forward_list& other);
        private:
            Node<T> head;
        }; // forward_list
        
        template <typename T>
        void forward_list<T>::push_front(const T& data) {
            Node<T>* new_node = get_node(data);
            new_node->next = head.next;
            head.next = new_node;
        }
    
        template <typename T>
        template <typename... Args>
        Node<T>* 
        forward_list<T>::get_node(Args&&... args){
            Node<T>* ret = new Node<T>(args...);
            return ret;
        }
        template <typename T>
        iterator<T>
        forward_list<T>::insert_after(iterator<T> it, const T& data) {
            auto new_node = get_node(data);
            new_node->next = it->next;
            it->next = new_node;
            return iterator(new_node);
        }
        
        template <typename T>
        iterator<T>
        forward_list<T>::begin() {
            return iterator<T>(head.next);
        }
        
        template <typename T>
        iterator<T>
        forward_list<T>::end() {
            return iterator<T>(nullptr);
        }
        template <typename T>
        iterator<T>
        forward_list<T>::before_begin()noexcept{
            return (iterator<T>(&head));
        }
        
        template <typename T>
        void 
        forward_list<T>::release() {
            Node<T>* trans = head.next;
            while (trans != nullptr) {
                Node<T>* temp = trans;
                trans = trans->next;
                delete temp;
            }
            head.next = nullptr;
        }
        
        template <typename T>
        Node<T>*
        forward_list<T>::copy(const forward_list<T>& other) {
            Node<T> first;
            Node<T>* trans = other.head.next, *pre = &first, *temp;
            while (trans != nullptr) {
                temp = get_node(trans->data);
                pre->next = temp;
                pre = temp;
                trans = trans->next;
            }
            return first.next;
        }
        template <typename T>
        forward_list<T>::forward_list(std::initializer_list<T> il) {
            Node<T>* tail = &head, *temp;
            head.next = nullptr;
            auto it = il.begin();
            while (it != il.end()) {
                temp = get_node(*it); 
                temp->next = tail->next;
                tail->next = temp;
                tail = temp;
                ++it;
            }
        }

        template <typename T>
        forward_list<T>& 
        forward_list<T>::operator=(std::initializer_list<T> il) {
            this->release();
            Node<T>* tail = &head, *temp;
            auto it = il.begin();
            while (it != il.end()) {
                temp = get_node(*it);
                temp->next = tail->next;
                tail->next = temp;
                tail = temp;
                ++it;
            }
            return *this;
        }
        
        template <typename T>
        forward_list<T>::forward_list(const forward_list<T>& other) {
            head.next = forward_list<T>::copy(other);
        }
        
        template <typename T>
        forward_list<T>& forward_list<T>::operator=(const forward_list<T>& other) {
            if (this == &other)
                return *this;
            this->release();
            head.next = forward_list<T>::copy(other);
            return *this;
        }
        
        template <typename T>
        forward_list<T>::forward_list(forward_list<T>&& other) {
            if (this == &other)
                return ;
            this->head.next = other.head.next;
            other.head.next = nullptr;
        }
        
        template <typename T>
        forward_list<T>&
        forward_list<T>::operator=(forward_list<T>&& other) {
            if (this == &other)
                return *this;
            this->release();
            this->head.next = other.head.next;
            other.head.next = nullptr;
            return *this;
        }

        template <typename T>
        forward_list<T>::~forward_list() {
            this->release();
        }

        void test01() {
            std::cout << " --- test01() --- " << std::endl;
            forward_list<int> lt;
            for (int i = 0; i < 20; ++i) {
                lt.push_front(i);
            }
            auto print = [](auto& lt){
                std::cout << "print lt : ";
                for (auto& trans : lt) {
                    std::cout << trans << " ";
                }
                std::cout << std::endl;
            };
            print(lt);
            lt.insert_after(lt.before_begin(), -20);
            lt.insert_after(lt.before_begin(), -10);
            lt.insert_after(lt.before_begin(), -30);
            print(lt);

            forward_list<int> lt2(lt);
            forward_list<int> lt3(std::move(lt2));
            forward_list<int> lt4;
            forward_list<int> lt5 = lt4;
            lt5 = lt;
            lt4 = std::move(lt);
        }

        void test02() {
            Node<int> n1(std::move(10));
            Node<int> n2(20);
            auto print_node = [&](auto& n) {
                std::cout << "data : " << n.data << " " << "next : " << n.next << std::endl;
            };
            print_node(n1);
            print_node(n2);
            n1 = 30;
            n2 = std::move(40);
            print_node(n1);
            print_node(n2);
        }
        
        void test03() {
            forward_list<int> lt = {10, 20, 30, 40};
            auto print = [](auto& lt) {
                std::cout << "print lt : ";
                for (auto& trans : lt) {
                    std::cout << trans << " ";
                }
                std::cout << std::endl;
            };
            print(lt);
            auto it = lt.begin();
            std::cout << *it++ << std::endl;
            std::cout << *++it << std::endl;
            lt = {40,50,60,70,80};
            print(lt);
        }
    } // namespace v2

} // namespace test


int main() {
    test::v2::test03();


    return 0;
}