#include <iostream>
#include <string>

struct Sales_data {
    std::string m_bookNo;
    unsigned m_units_sold;
    double m_revenue;
};

int main() {
    int b = 10;
    int& ref = b;
    auto a = ref;
    a = 20; 
    std::cout << b << std::endl;
    decltype(ref) ref2 = a;

    


    return 0;
}