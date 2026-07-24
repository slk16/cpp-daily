#include <iostream>
#include <vector>
#include <cstdio>
#include <memory>
#include <algorithm>

namespace test {
    namespace v1 {
        
        template <typename T>
        class unique_ptr {
        public:
            unique_ptr() : ptr(nullptr) {}
            unique_ptr(T* p) : ptr(p) {};
            unique_ptr(const unique_ptr& other) = delete;
            unique_ptr<T>& operator=(const unique_ptr& other) = delete;
            unique_ptr(unique_ptr&& other) {
                ptr = std::move(other.ptr);
                other.ptr = nullptr;
            }
            unique_ptr<T>& operator=(unique_ptr&& other) {
                if (ptr != nullptr)
                    delete ptr;
                ptr = std::move(other.ptr);
                other.ptr = nullptr;
                return *this;
            }
            ~unique_ptr<T>() {
                if (ptr != nullptr)
                    delete ptr;
            }
        public:
            T& operator*() {
                return *ptr;
            }
            T* operator->() {
                return ptr;
            }
            explicit operator bool() {
                return ptr != nullptr;
            }
        public:
            T* get() {
                return ptr;
            }
            T* release() {
                T* temp =  ptr;
                ptr = nullptr;
                return temp;
            }
            void reset() {
                if (ptr != nullptr)
                    delete ptr;
                ptr = nullptr;
            }
        private:
            T* ptr;
        };// class unique_ptr
        
        template<typename T, typename... Args>
        unique_ptr<T> make_unique(Args&&... args) {
            return unique_ptr<T>(new T(std::forward<Args>(args)...));
        }
        
        void test01() {
            using test::v1::unique_ptr;
            using test::v1::make_unique;
            
            struct Person{
                Person(std::string name, int age) :name_(name), age_(age) { std::cout << "Person " << name << "(age : " << age << " ) Constructed" << std::endl;}
            private:
                std::string name_;
                int age_;
            };
            
            unique_ptr<int> ip = make_unique<int>(3);
            unique_ptr<Person> pp = make_unique<Person>("xiaoming", 20); 
        }

    } // namespace v1
    
    namespace file_prac {
        void test01() {

            FILE* file = fopen("test.txt", "w");
            if (file == nullptr)
                return ;
            fprintf(file, "Hello %s\n", "world");
            fputs("Hello again\n", file);
            
            fclose(file);
        }
        
        void test02() {
            FILE* file = fopen("test.txt", "r");
            if (file == nullptr)
                throw std::runtime_error("failed to open file");
            char buff[1024];
            fgets(buff, 1024, file);
            std::cout << buff << std::endl;
            std::cout << buff << std::endl;
            fclose(file);
        }
        
        void test03() {
            FILE* file = fopen("test.txt", "a");
            if (file ==nullptr)
                throw std::runtime_error("failed to open file");
            fputs("hello\n", file); 
            fclose(file);
        }
        
        void test04() {
            FILE* file = fopen("test.txt", "a+");
            if (file == nullptr)
                throw std::runtime_error("failed to open file");
            fprintf(file, "Hello");
            char buff[1024];
            rewind(file);
            fscanf(file, "%s", buff);
            std::cout << buff << std::endl;
            fclose(file);
        }

    } // file_prac

    namespace v2 {
        void file_deleter(FILE* xfile) {
            if (xfile != nullptr)
                fclose(xfile);
        }
        void test01() {
            std::unique_ptr<FILE, void(*)(FILE*)> fp(fopen("test.txt", "w"), file_deleter);
            //采用RAII思想封装了c风格文件，资源释放并不可以使用default_deleter，所以要传入自定义deleter
            fprintf(fp.get(),"hello world");
            std::cout << "sizeof(fp) : " << sizeof(fp) << std::endl;
            // sizeof it : 16
            std::cout << "sizeof(unique_ptr) : " << sizeof(std::unique_ptr<FILE>) << std::endl;
            // sizeof it : 8 
        }
        
        void test02() {
            auto deleter= [](FILE* xfile) {if (xfile != nullptr) fclose(xfile);};
            std::unique_ptr<FILE,decltype(deleter)> fp(fopen("test.txt", "w+"), deleter);
            fprintf(fp.get(), "nihao xiaoming");
            std::cout << "sizeof(fp) with labmda deleter : " << sizeof(fp) << std::endl;
        }
        
        void test03() {
            struct file_deleter {
                void operator()(FILE* xfile) {
                    if (xfile != nullptr)
                        fclose(xfile);
                }
            };
            std::unique_ptr<FILE, file_deleter> fp(fopen("test.txt", "w+"), file_deleter{});
            fprintf(fp.get(), "Hello from funtor deleter");
            std::cout << "sizeof(fp) with functor deleter : " << sizeof (fp) << std::endl;
        }
    } // namespace v2
      // 
    

    namespace v3 {
        void test() {
            using std::vector;
            vector<int> v;
            v = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8};
            auto it = std::upper_bound(v.begin(), v.end() ,4);
            std::cout << "upper_bount : " << it.base() << std::endl;
        }

    } // namespace v3
    
} // namespace test



int main(){
    test::v2::test02();

    return 0;
}