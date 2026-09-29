#include <iostream>
#include <thread>
#include <numeric>
#include <vector>
namespace test
{
  namespace t1
  {
    struct foo
    {
      int val1;
      int & ref_val2;
      inline foo(int & ref)
      : val1{ref}
      , ref_val2{this->val1}
      {
      }
      
      inline void operator()() const
      {
        std::operator<<(std::cout, "val1 : ").operator<<(this->val1).operator<<(std::endl);
        std::operator<<(std::cout, "ref_val : ").operator<<(this->ref_val2).operator<<(std::endl);
      }
      
    };
    
    struct bar
    {
      int val1;
      int & val2;
      int * val3;
      inline bar()
      : val1{3}
      , val2{this->val1}
      , val3{&this->val2}
      {
      }
      
    };
    
    void test01()
    {
      std::operator<<(std::cout, " --- test01() --- ").operator<<(std::endl);
      int val = 20;
            
      class __lambda_27_27
      {
        public: 
        inline /*constexpr */ void operator()() const
        {
          val = 30;
        }
        
        private: 
        int & val;
        
        public:
        __lambda_27_27(int & _val)
        : val{_val}
        {}
        
      };
      
      __lambda_27_27 change = __lambda_27_27{val};
      std::operator<<(std::cout, "val : ").operator<<(val).operator<<(std::endl);
      change.operator()();
      std::operator<<(std::cout, "val : ").operator<<(val).operator<<(std::endl);
    }
    void test02()
    {
      std::operator<<(std::cout, " --- test02() --- ").operator<<(std::endl);
      int a = 20;
      std::cout.operator<<(a).operator<<(std::endl);
      const foo val = foo(a);
      std::operator<<(std::cout, "val.ref_val2 = 20").operator<<(std::endl);
      val.ref_val2 = 20;
      val.operator()();
      std::operator<<(std::cout, "val.ref_val2 = 30").operator<<(std::endl);
      val.ref_val2 = 30;
      val.operator()();
    }
    void test03()
    {
      std::operator<<(std::cout, " --- test03() --- ").operator<<(std::endl);
      bar a = bar();
    }
    void test04()
    {
      std::operator<<(std::cout, " --- test04() --- ").operator<<(std::endl);
      const int a = 20;
      class write
      {
        inline write(int & val)
        {
          val = 30;
        }
        
      };
      
    }
    void test05()
    {
      const int a = 20;
      const int & ref = a;
      const int * cip = &a;
      int * ip = const_cast<int *>(cip);
    }
    void test06()
    {
    }
    
  }
  namespace t2
  {
    template<typename InputIterator>
    auto sum(InputIterator first, InputIterator last)
    {
      auto result = std::accumulate(first, last, typename std::remove_reference<decltype(*first)>::type());
      return result;
    }
    
    #ifdef INSIGHTS_USE_TEMPLATE
    template<>
    int sum<__gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > >(__gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > first, __gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > last)
    {
      int result = std::accumulate(__gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > >(first), __gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > >(last), typename std::remove_reference<decltype(* first)>::type());
      return result;
    }
    #endif
    
    void test01()
    {
      std::vector<int, std::allocator<int> > iv = std::vector<int, std::allocator<int> >();
      iv.operator=(std::initializer_list<int>{1, 2, 9, 3, 4, 5});
      std::cout.operator<<(sum(iv.begin(), iv.end())).operator<<(std::endl);
    }
    
  }
  namespace t3
  {
    template<bool , typename T = void>
    struct enable_if
    {
    };
    
    template<typename T>
    struct enable_if<true, T>
    {
      using type = T;
    };
    
    template<bool Cond, typename T>
    using enable_if_t = typename enable_if<Cond, T>::type;
    template<typename T>
    std::basic_string<char> to_string(T val, std::enable_if_t<std::is_arithmetic_v<T>, int>)
    {
      return std::to_string(val);
    }
    
    /* First instantiated from: day20260811.cpp:113 */
    #ifdef INSIGHTS_USE_TEMPLATE
    template<>
    std::basic_string<char> to_string<int>(int val, std::enable_if_t<std::is_arithmetic_v<int>, int>)
    {
      return std::to_string(val);
    }
    #endif
    
    template<typename T>
    std::basic_string<char> to_string(T val, std::enable_if_t<!std::is_arithmetic_v<T>, int>)
    {
      return std::basic_string<char>("NaN", std::allocator<char>());
    }
    void test01()
    {
      namespace ts = t3;
      int ival = 5;
      std::basic_string<char> sval = std::basic_string<char>("hello", std::allocator<char>());
      std::operator<<(std::operator<<(std::cout, "int 5 to_string : "), (to_string(ival, 0))).operator<<(std::endl);
    }
    
  }
  namespace t4
  {
    void test01()
    {
    }
    
  }
  
}

int main()
{
  return 0;
}
