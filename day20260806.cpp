#include <iostream>
#include <sstream>
#include <execution>
#include <random>
#include <vector>
#include <algorithm>
#include <optional>
#include <chrono>
#include <limits>
namespace test {
    namespace t1 {
        void test01() {
            int a = -15;
            std::cout << "a >> 2 : " << (a >> 2) << std::endl; 
            std::cout << "a / 4  : " << (a / 4) << std::endl;
        } 
        void test02() {
            std::optional<int> ret = 10;
            ret.reset();
            if (ret.has_value())
                std::cout << ret.value() << std::endl;
        }

        void test03(){
            int* p = new int(4);
            new (p) int(5);
            std::cout << *p << std::endl;
            delete p;
        }
        
        void test04() {
            std::vector<int> vi;
            std::cout << "vi.capacity() : " << vi.capacity() << std::endl;
            std::cout << "vi.reserve(11)" << std::endl;
            vi.reserve(11);
            std::cout << "vi.capacity() : " << vi.capacity() << std::endl;
            auto print = [&]() {
                std::cout << "vector : ";
                for (auto& trans : vi) {
                    std::cout << trans << " ";
                }
                std::cout << std::endl;
            };
            std::cout << std::endl;
            for (int i = 0; i < 16; ++i) {
                vi.push_back(i + 1);
                print();
                std::cout << "vi.capacity() : " << vi.capacity() << std::endl;
                std::cout << std::endl;
            }
        }
        void test05() {
            using Rep = std::chrono::high_resolution_clock::rep;
            std::cout << std::numeric_limits<Rep>::min() << std::endl;
            std::cout << std::numeric_limits<Rep>::max() << std::endl;
        }
    }
    namespace test_sort {
        class SortMethod{
        public:
            SortMethod(const std::string& name, void (*method)(std::vector<int>& arr, int l, int r)) : name_(name), method_(method){}
            std::string name_;
            void (*method_)(std::vector<int>&, int l, int r);   
        };
        void selection_sort(std::vector<int> &arr, int l, int r) {
            if (r - l + 1 < 2)
                return ;
            int i;
            for (i = l; i < r; ++i) {
                int ind = i;
                for (int j = i + 1; j <= r; ++j) {
                    if (arr[j] < arr[ind])
                        ind = j; 
                }
                std::swap(arr[i], arr[ind]);
            }
        }
        void insertion_sort(std::vector<int>& arr, int l, int r) {
            if (r - l < 1)
                return ;
            for (int i = l + 1; i <= r; ++i) {
                int j = i;
                while (j > l && arr[j] < arr[j - 1]) {
                    std::swap(arr[j], arr[j - 1]);
                    --j;
                }
            }
        }
        void unguarded_insertion_sort(std::vector<int>& arr, int l, int r) {
            if (l == r)
                return ;
            int ind = l;
            for (int i = l + 1; i <= r; ++i) {
                if (arr[ind] > arr[i])
                    ind = i;
            }
            std::swap(arr[l], arr[ind]);
            for (int i = l + 1; i <= r; ++i) {
                int j = i;
                while (arr[j - 1] > arr[j]) {
                    std::swap(arr[j], arr[j - 1]);
                    --j;
                }
            }
        }
        void shell_sort(std::vector<int>& arr, int l, int r) {
            for (int tap = (r - l + 1) >> 1; tap >= 1; tap >>= 1) {
                for (int i = l + tap; i <= r; ++i) {
                    for (int j = i - tap; j >= l && arr[j] > arr[j + tap]; j -= tap) {
                        std::swap(arr[j], arr[j + tap]);
                    }
                }
            }            
        } 
        void shell_sort_hibbard(std::vector<int>& arr, int l, int r) {
            int gap = r - l + 1;
            if (gap < 2)
                return ;
            if (gap >= 4) {
                gap |= gap >> 1;
                gap |= gap >> 2;
                gap |= gap >> 4;
                gap |= gap >> 8;
                gap |= gap >> 16;
                gap >>= 2;
            } else {
                gap = 1;
            }
            for(; gap >= 1; gap >>= 1) {
                for (int i = l + gap; i <= r; ++i) {
                    for (int j = i - gap; j >= l && arr[j] > arr[j + gap]; j -= gap) {
                        std::swap(arr[j], arr[j + gap]);
                    }
                }
            }
        }
        void bubble_sort(std::vector<int>& arr, int l, int r) {
            if (r - l < 2)
                return ;
            for (int i = r; i > l; --i) {
                bool flag = 1;
                for (int j = l; j < i; ++j) {
                    if (arr[j] > arr[j + 1])
                    {
                        std::swap(arr[j], arr[j + 1]);
                        flag = 0;
                    }
                }
                if (flag)
                    break;
            }
        }
        enum class Strategy{
            Random,
            Ordered,
            ReverseOrdered
        };
        namespace quick_sort {
            namespace v0 {
                void quick_sort(std::vector<int>& arr, int left, int right) {
                    if (left >= right) return ;
                    if (right - left == 1 && arr[left] > arr[right])
                        std::swap(arr[left], arr[right]); 
                    int l = left, r = right;
                    int p = arr[((right - left) >> 2) + left];
                    while (l < r) {
                        while (l < r && arr[r] >= p) --r;
                        if (l < r) arr[l++] = arr[r];
                        while (l < r && arr[l] <= p) ++l;
                        if (l < r) arr[r--] = arr[l];
                    } 
                    arr[l] = p;
                    quick_sort(arr, left, l - 1);
                    quick_sort(arr, l + 1, right);
                }
            }
            namespace v1 {
                void quick_sort(std::vector<int>& arr, int left, int right) {
                    if (left >= right)
                        return ;
                    int p = arr[left], r = right, l = left;
                    do {
                        while (arr[r] > p) --r;
                        while (arr[l] < p) ++l;
                        if (l <= r) {
                            std::swap(arr[l], arr[r]); 
                            ++l;
                            --r;
                        }
                    } while (l <= r);
                    quick_sort(arr, left, r);
                    quick_sort(arr, l, right);
                    return ;
                }

            }
            //namespace v2{
            //    void quick_sort(std::vector<int> &arr, int left, int right) {
            //    }
            //}
        }
        void test_sort(std::initializer_list<SortMethod>, int size = -1, Strategy s = Strategy::Random);
        // ------------- test -------------
        void test01() {
            using test::test_sort::quick_sort::v1::quick_sort;
            test_sort({
                /*SortMethod("selection_sort", selection_sort),
                SortMethod("insertion_sort", insertion_sort),
                SortMethod("unguarded_insertion_sort", unguarded_insertion_sort),
                SortMethod("shell_sort", shell_sort),
                SortMethod("shell_sort_hibbard", shell_sort_hibbard),
                SortMethod("bubble_sort", bubble_sort),*/
                SortMethod("quick_sort", quick_sort)
            }, 10000, Strategy::ReverseOrdered);

        }
        // ------------- test -------------
        std::pair<std::vector<int>,std::vector<int>> get_random_data(int size = -1);
        std::pair<std::vector<int>,std::vector<int>> get_ordered_data(int size = -1);
        std::pair<std::vector<int>, std::vector<int>> get_reverse_ordered_data(int size = -1);
        void test_sort(std::initializer_list<SortMethod> methods, int size, Strategy s)
        {
            if (methods.size() < 1)
                return ;
            std::pair<std::vector<int>, std::vector<int>> data;
            std::cout << "Strategy : ";
            if (s == Strategy::Random) {
                std::cout << "Random";
                if (-1 != size){
                    data = get_random_data(size);
                } else {
                    data = get_random_data();
                }
            } else if (s == Strategy::ReverseOrdered) {
                std::cout << "Ordered";
                if (-1 != size) {
                    data = get_ordered_data(size);
                } else {
                    data = get_ordered_data();
                }
            } else if (s == Strategy::ReverseOrdered) {
                std::cout << "ReverseOrdered";
                if (-1 != size) {
                    data = get_reverse_ordered_data(size);
                } else {
                    data = get_reverse_ordered_data();
                }
            }
            std::cout << std::endl;
            size = data.first.size();
            std::chrono::steady_clock::time_point b;
            std::chrono::steady_clock::time_point e;
            std::chrono::steady_clock::duration time;
            int buff_size;

            std::cout << "size : " << size << std::endl;
            for (auto& trans : methods) {
                std::ostringstream buff;
                buff << std::endl << " --- test for " << trans.name_ << " --- " << std::endl << std::endl;
                buff_size = buff.tellp();
                std::cout << buff.str();
                b = std::chrono::steady_clock::now();            
                trans.method_(data.first, 0, size - 1);
                e = std::chrono::steady_clock::now();
                time = e - b;
                if (std::is_sorted(data.first.begin(), data.first.end())) {
                    std::cout << "type : " << trans.name_ << " is " << "\033[1;32m" << "sorted" << "\033[0m" << " =)" << std::endl;
                } else {
                    std::cout << "type : " << trans.name_ << " is " << "\033[1;31m" << "unsorted" << "\033[0m" << " !!!" << std::endl;
                }
                std::cout << "type : " << trans.name_ << "() cost : " << time.count()  << " ns " << std::endl;
                std::cout << std::string(buff_size - 3, '-');
                data.first = data.second;
            }
            std::cout << std::endl;
            b = std::chrono::steady_clock::now();
            //std::sort(data.second.begin(), data.second.end());
            std::sort(std::execution::par, data.second.begin(), data.second.end());
            e = std::chrono::steady_clock::now();
            time = e - b;
            std::cout << "std::sort() cost : " << time.count()  << " ns "<< std::endl;
            //std::cout << "data.first.size() : " << data.first.size() << std::endl;
            //std::cout << "data.first.capacity() : " << data.first.capacity() << std::endl; 
            //std::cout << "data.second.size() : " << data.second.size() << std::endl;
            //std::cout << "data.second.capacity() : " << data.second.capacity() << std::endl; 
            //std::cout << " --- " << name << "() : --- " << std::endl;
            //for (auto& trans : data.first) {
            //    std::cout << trans << " ";                
            //}
            //std::cout << std::endl;
            //std::cout << " --- std::sort() --- " << std::endl;
            //for (auto& trans : data.second) {
            //    std::cout << trans << " ";                
            //}
        }
        inline int random_No(int first = 0, int last = 10000) { // [first, last]
            static std::default_random_engine e(std::random_device{}());
            std::uniform_int_distribution<int> u(first, last);
            return u(e);
        }
        std::pair<std::vector<int>, std::vector<int>>
        get_ordered_data(int size) {
            std::pair<std::vector<int>, std::vector<int>> ret;
            if (size == -1) {
                size = random_No();

            }
            ret.first.resize(size); 
            ret.second.resize(size);
            std::iota(ret.first.begin(), ret.first.end(), 1);
            std::iota(ret.second.begin(), ret.second.end(), 1);
            return ret;
        }
        std::pair<std::vector<int>, std::vector<int>>
        get_reverse_ordered_data (int size){
            if (size == -1)
                size = random_No();
            std::pair<std::vector<int>, std::vector<int>> ret;
            ret.first.resize(size);
            ret.second.resize(size);
            std::iota(ret.first.rbegin(), ret.first.rend(), random_No());
            std::iota(ret.second.rbegin(), ret.second.rend(), random_No());
            return ret;
        }
        std::pair<std::vector<int>, std::vector<int>>
        get_random_data(int size)
        {
            std::pair<std::vector<int>, std::vector<int>> ret;
            if (size == -1)
            {
                size = random_No();
            }
            std::uniform_int_distribution trans(0, size);
            ret.first.reserve(size);
            ret.second.reserve(size);
            int temp = 0;
            for (int i = 0; i < size; ++i)
            {
                temp = random_No();
                ret.first.push_back(temp);
                ret.second.push_back(temp);
            }
            return ret;
        }
    }

} // namespace test

int main(){
    //test::t1::test05();
    test::test_sort::test01();  
    

    return 0;
}

//using namespace std;
//struct Data{
//    Data(int p, int d) : p_(p), d_(d){ }    
//    bool operator<(const Data& other) const {
//        if (this->d_ != other.d_) return d_ < other.d_;
//        else return p_ > other.p_;
//    }
//    int p_;
//    int d_;
//};
//
//int main() {
//    int n, d, p;
//    cin >> n;
//    using PII = std::pair<int,int>;
//    set<PII> st;
//    vector<Data> da;
//    for (int i = 0; i < n; ++i) {
//        cin >> p >> d;
//        da.push_back(Data(p, d));
//    }
//    std::sort(da.begin(), da.end());
//    for (int i = 0; (unsigned long) i < da.size(); ++i) {
//        if (da[i].d_ > st.size()) {
//            st.insert({da[i].p_, i});            
//        } else {
//            if (da[i].p_ > st.begin()->first) {
//                st.erase(st.begin());
//                st.insert({da[i].p_, i});
//            }
//        }
//    }
//    int sum = 0;
//
//    for (auto& trans : st) {
//        sum += trans.first;        
//    }
//    std::cout << sum << std::endl;
//
//    return 0;
//}