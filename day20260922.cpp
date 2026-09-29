#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>


namespace test {

    template <typename... T>
    struct TypeList {};

    template <typename T, typename U> 
    struct Pair {
        using first = T;
        using second = U;
    };

    template <typename T1, typename T2> struct Concat;

    template <typename... As, typename... Bs>
    struct Concat<TypeList<As...>, TypeList<Bs...>> {
        using type = TypeList<As...,Bs...>;
    };
    template <typename T1, typename T2>
    using Concat_t = typename Concat<T1,T2>::type;

    template <typename T>
    struct PrintTypeList;
    
    template <typename T, typename... Ts>
    struct PrintTypeList<TypeList<T, Ts...>> {
        static void run() {
            std::cout << typeid(T).name() << std::endl;
            PrintTypeList<TypeList<Ts...>>::run();
        }
    };
    
    template <>
    struct PrintTypeList<TypeList<>> {
        static void run() {}
    };
    
    template <typename T1>
    struct Length;

    template <typename... Ts>
    struct Length<TypeList<Ts...>> {
        static constexpr std::size_t value = sizeof...(Ts);
    };
    template <typename T>
    inline constexpr std::size_t Length_v = Length<T>::value;

    void test01() {
        using pis = Pair<int, std::string>;
        pis::first a = 20;
        pis::second b = "std::string";
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
    }
    
    void test02() {
        TypeList<> void_list;
        TypeList<int,double,std::string,bool> list1;
        TypeList<std::vector<int>, std::string> list2;
        auto list3 = Concat_t<decltype(list1), decltype(list2)>{};
        std::cout << "typeid(list3).name() : " << typeid (list3).name() << std::endl;
        std::cout << std::endl;
        PrintTypeList<decltype(list3)>::run();
    }

    void test03() {
        using list = TypeList<int, float, double, std::string, std::vector<int>>;
        std::cout << "length of list is " << Length<list>::value << std::endl;
        std::cout << std::boolalpha << std::is_integral_v<bool> << std::endl;
    }

    template <template <typename> class F, typename List>
    struct Map;

    template <template <typename> class F, typename... Ts>
    struct Map<F , TypeList<Ts...>> {
        using type = TypeList<F<Ts>...>;
    };

    template <template <typename> class F, typename List>
    using Map_t = typename Map<F,List>::type;

    template <typename T>
    struct AddPointer {
        using type = T*;
    };
    template <typename T>
    using AddPointer_t = typename AddPointer<T>::type;
    void test04() {
        using list = TypeList<int, double, std::string>;
        std::cout << std::endl << "list : " << std::endl << std::endl;
        PrintTypeList<list>::run();
        std::cout << std::endl << "then add pointer : " << std::endl << std::endl;
        PrintTypeList<Map_t<AddPointer_t, list>>::run();
    }
        
    template <template <typename> typename Pred, typename T>
    struct Filter;
    template <template <typename> typename Pred, typename T, typename... Ts>
    struct Filter<Pred, TypeList<T, Ts...>> {
        using type = Concat_t<
            std::conditional_t<Pred<T>::value, TypeList<T>, TypeList<>>,
            typename Filter<Pred, TypeList<Ts...>>::type>;
    };
    template <template <typename> typename Pred>
    struct Filter<Pred, TypeList<>> {
        using type = TypeList<>;
    };
    void test05() {
        using list = TypeList<int, float*, std::string*, double*, std::vector<int>>;
        using ret1 = list;
        std::cout << "type : " << std::endl;
        PrintTypeList<ret1>::run();
        //using ret2 = Filter<as_trait<is_pointer_v>, list>;
    }
    void test06() {

    }
} // namespace test
;
int main() {
    test::test05();




    return 0;
}