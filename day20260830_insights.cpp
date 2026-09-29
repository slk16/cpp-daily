#include <iostream>
#include <thread>

namespace test
{
  template<typename T>
  void func(const T & a)
  {
    (std::cout << *a) << std::endl;
  }
  
  /* First instantiated from: day20260830.cpp:11 */
  #ifdef INSIGHTS_USE_TEMPLATE
  template<>
  void func<std::unique_ptr<int, std::default_delete<int> > >(const std::unique_ptr<int, std::default_delete<int> > & a)
  {
    std::cout.operator<<(a.operator*()).operator<<(std::endl);
  }
  #endif
  
  void test01()
  {
    std::unique_ptr<int, std::default_delete<int> > uptri = std::make_unique<int>(20);
    std::thread th = std::thread{func<std::unique_ptr<int, std::default_delete<int> > >, std::move(uptri)};
    th.join();
  }
  
}

int main()
{
  test::test01();
  return 0;
}
