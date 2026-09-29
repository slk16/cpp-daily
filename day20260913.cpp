#include <fstream>
#include <iostream>
#include <regex>
#include <algorithm>
#include <sstream>

namespace test01 {
    void test01() {
        std::regex pattern{R"((\d{3})-(\d{4})-(\d{4}))"};
        std::string a = "133-4366-3242 134-4522-3134";
        std::smatch match_ret;
        auto ret = std::regex_search(a, match_ret, pattern);
        if (ret) {
            std::cout << "ret : " << std::boolalpha << ret << std::endl;
            std::cout << "match_ret.str() : " << match_ret.str() << std::endl;
            std::cout << "match_ret.suffix() : " << match_ret.suffix() << std::endl;
            std::cout << "match_ret.prefix() : " << match_ret.prefix() << std::endl;
            std::cout << "match_ret.size() : " << match_ret.size() << std::endl;
            std::cout << "match_ret.str(0) : " << match_ret.str(0) << std::endl;
            std::cout << "match_ret.str(1) : " << match_ret.str(1) << std::endl;
            std::cout << "match_ret.str(2) : " << match_ret.str(2) << std::endl;
            std::cout << "match_ret.str(3) : " << match_ret.str(3) << std::endl;
        } else {
            std::cout << "fail to match" << std::endl;
        }
    }
    void test02() {
        //std::string str;
        //std::regex_iterator<std::string::const_iterator> reit(str.begin(), str.end(), re);
        std::regex re(R"(\s*std::cout <<( .* )<< std::endl;)");
        std::ifstream ifs{ "./day20260913.cpp", std::ios::in};
        if(ifs.is_open()) {
            std::cout << "success to open()" << std::endl;
        } else {
            std::cout << "fail to open()" << std::endl;
        }
        std::string trans;
        std::smatch mch_ret;
        bool ret;
        std::cout << "search : " << std::endl;
        while (std::getline(ifs, trans)) {
            ret = std::regex_match(trans, mch_ret, re);
            if (ret) {
                std::cout << mch_ret.str(1) << std::endl;
            }
        }
    }
    void test03() {
        std::string s{"a1 b2 c3 d4"};
        std::regex re(R"(\d+)");
        std::regex_iterator<std::string::const_iterator> reit {s.begin(), s.end(), re}, end;
        auto dist = std::distance(reit, end);
        std::cout << "distance : " << dist << std::endl;
        for (;reit != end; ++reit) {
            std::cout 
                << "value = " << reit->str() 
                << ", "
                << "prefix = " << reit->prefix()
                << ", "
                << "subfix = " << reit->suffix()
                << std::endl;           
        }
    }
    void test04() {
        std::string str;
        for (int i = 0; i < 26; ++i){// make str to a b c...
            str.push_back('a' + i);
            str.push_back(' ');
        } 
        std::cout << "str : " << str << std::endl;
        std::regex re {R"(\s+)"};
        std::sregex_token_iterator it{ str.begin(), str.end(), re, -1}, end;
        std::ostringstream oss;
        for (; it != end; ++it) {
            oss << it->str() << ",";
        }
        std::cout
            << "result : "
            << std::endl
            << oss.str()
            << std::endl;
    }
    void test05() {
        std::string s{"hello 123 world 456 end"}, str2;
        std::regex re{R"(\d+)"};
        auto print = [&] {
            std::cout << std::endl
            << "s : " << s << std::endl
            << "str2 : " << str2 << std::endl
            << std::endl;
        };
        str2 = std::regex_replace(s, re, "[$&]");
        print();
        str2 = std::regex_replace(s, re, "[$&]", std::regex_constants::format_first_only);
        print();
        str2 = std::regex_replace(s, re, "[$&]", std::regex_constants::format_no_copy);
        print();
        str2 = std::regex_replace(s, re, "[$&]", std::regex_constants::format_no_copy | std::regex_constants::format_first_only);
        print();
        str2 = std::regex_replace(s, re, R"([\0])", std::regex_constants::format_sed);;
        print();
    }
    void test06() {
        std::string s {"a1 b22 c333 d4444"}, result;
        std::regex re {R"delim(([a-z]+)(\d+))delim"};
        for (std::sregex_iterator it(s.begin(), s.end(), re), end;
            it != end;
            ++it) {
            int n = std::stoi(it->str(2));                
            result += it->prefix();
            result += it->str(1);
            result += std::to_string(n * 2);
            if (std::next(it) == end) {
                result += it->suffix();
            }
        }
        std::cout << "result : " << result << std::endl;
    }
    void test07() {
        std::string s { R"target( <b>title for string.<\b>, <p>paragraph : hello world<\p>)target"};
        std::regex re1(R"(<.*>)");
        std::regex re2(R"(<.*?>)");
        std::smatch m;
        std::regex_search(s, m, re1);
        std::cout << "m : " << m[0] << std::endl;
        std::sregex_iterator it(s.begin(), s.end(), re2), end;
        for (; it != end; ++it) {
            std::cout << it->str() << ' ';
        }
        std::cout << '\n';
    }

} // namespace test01
namespace test02 {
    void foo(std::string str) {
        std::cout << str << std::endl;
    }
    void bar(std::regex re) {
        std::cout << re.flags() << std::endl;
    }
    void test01() {
        foo("hello world");//non-explicit for constructor std::string(const char*);

        std::regex re1("const char");// explicit construct regex
        //bar("const char");//non-explicit construction for regex is not allowed
        //std::regex re2 = "const char"; //also non-explicit construction
    }
}

int main() {
    test01::test07();

    return 0;
}