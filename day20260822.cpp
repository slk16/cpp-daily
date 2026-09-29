#include <iostream>
#include <string>
#include <fstream>
namespace test {
    namespace extract {
        void extract() {
            const std::string::size_type size_key = 7;
            std::string temp;
            std::fstream f;
            f.open("./subtitles", std::ios::out);
            if (f.is_open()) {
                std::cout << "success to open" << std::endl;
                std::string trans;
                while (std::getline(std::cin, temp)) {
                    std::string::size_type value_left, value_right, quote_pos;
                    if ((quote_pos = temp.find("content")) != std::string::npos) {
                        std::cout << "temp : " << temp << std::endl;
                        quote_pos += size_key + 1;
                        std::cout << "step 1 " << std::endl;
                        value_left = temp.find('"', quote_pos + 1);
                        std::cout << "step 2 " << std::endl;
                        value_right = temp.find('"', value_left + 1);
                        std::cout << "step 3 " << std::endl;
                        trans = temp.substr(value_left + 1, value_right - value_left - 1);
                        f << trans << std::endl;
                        std::cout << "step 4 " << trans << std::endl;
                    }
                }
                f.close();
            } else {
                std::cout << "open failed" << std::endl;
            }
        }
    }    
    void test01() {
        extract::extract();
    }

} // namespace test

int main() {
    test::test01();


    return 0;
}