#include <iostream>
#include <variant>
#include <iomanip>
#include <map>
#include <string>
#include <optional>

namespace test{
    namespace v1{
        class Result{
        public:
            static Result ok(int val) {return Result(val);}
            static Result err(std::string err) {return Result(err);}
            
            bool is_ok() { return std::holds_alternative<int>(val_);}
            bool is_err() {return !is_ok();}
            
            int value() { return std::get<int>(val_);}
            const std::string& error() {return std::get<Error>(val_).err_;}

        private:
            struct Error {
                std::string err_;
                Error(std::string err) : err_(std::move(err)) {};
            };
            std::variant<int, Error> val_;
            
            explicit Result(int val) : val_(val) {};
            explicit Result(std::string err) : val_(Error(std::move(err))) {};
        };
        void test01() {
            Result ret1 = Result::ok(5);
            if (ret1.is_ok())  
                std::cout << "success : " << ret1.value() << std::endl;
            else
                std::cout << "error : " << std::endl;
            Result ret2 = Result::err("failed");
            if (ret2.is_err())
                std::cout << "error : " << ret2.error() << std::endl;
            else 
                std::cout << "success" << std::endl;
        }
    } // namespace v1
    
    namespace v2 {
        template <typename T>
        class Result {
        public:
            static Result ok(T val) { return Result(std::move(val)); }
            static Result err(std::string val) { return Result(Error(std::move(val))); }

            bool is_ok() const { return std::holds_alternative<T>(val_); }
            bool is_err() const { return !is_ok(); }
            
            T& value() { return std::get<T>(val_); }
            const T& value() const { return std::get<T>(val_); }
            const std::string& error() const { return std::get<Error>(val_).err_; }
        private:
            struct Error {
                std::string err_;
                Error(std::string&& err) : err_(std::move(err)) {};
            };
            std::variant<T,Error> val_;
            explicit Result(T&& val ) : val_(std::move(val)) {};
            explicit Result(Error&& err) : val_(std::move(err)) {};
        }; // class Result
           
        template <>
        class Result<void> {
        public:
            static Result ok() { return Result<void>(true); }
            static Result err(std::string val) { return Result<void>(false, std::move(val)); }
          
            bool is_ok() const { return ok_; }
            bool is_err() const { return !ok_; }
            const std::string& error() const { return err_; }
        private:
            bool ok_;
            std::string err_;
            Result(bool ok) : ok_(ok) {};
            Result(bool ok, std::string&&err) : ok_(ok), err_(std::move(err)){};
        }; // Result
           
        void test01() {
            Result<int> ret1 = Result<int>::ok(20);
            if (ret1.is_ok())
                std::cout << "ok : " << ret1.value() << std::endl;
            else
                std::cout << "?" << std::endl;
            Result<int> ret2 = Result<int>::err("error");
            if (ret2.is_err())
                std::cout << "is a error" << ret2.error() << std::endl;
            else
                std::cout << "?" << std::endl;
            Result<std::string> ret3 = Result<std::string>::ok("what a string");
            if (ret3.is_ok())
                std::cout << "yes" << ret3.value() << std::endl;
            else
                std::cout << "no" << std::endl;
            auto ret4 = Result<void>::ok();
            if(ret4.is_ok())
                std::cout << "yes" << std::boolalpha << ret4.is_ok() << std::endl;
            else
                std::cout << "what ? " << std::endl;            
        }

    } // namespace v2
    
    namespace v3 {
        std::optional<int> map_find(const std::map<std::string, int>& mp, const std::string& key) {
            auto ret = mp.find(key);
            if (ret == mp.end())
                return std::nullopt;
            else
                return std::optional<int>(ret->second);
        }
        
        std::optional<int>mstoi(std::string str) {
            try {
                int ret = std::stoi(str);
                return std::optional<int>(ret);
            } catch (...) {
                return std::nullopt;
            }
        }

        void test01() {
            std::map<std::string, int> mp;
            mp["hi"] = 10;
            mp.emplace("hello", 30);
            mp.insert({"thank", 20});
            auto ret = map_find(mp, "hello");
            if (ret) {
                std::cout << std::boolalpha << ret.has_value() << std::endl;
                std::cout << ret.value() << std::endl; 
            }
            else
                std::cout << "not find" << std::endl;
        }
        
        void test02() {
            std::string str1("hello");
            std::string str2("123");
            std::string str3("132hello");
            auto ret1 = mstoi(str1);
            if (ret1)
                std::cout << typeid(decltype(ret1.value())).name() << " : " << ret1.value() <<  std::endl;
            auto ret2 = mstoi(str2);
            if (ret2.has_value())
                std::cout << typeid(decltype(ret2.value())).name() << " : " << ret2.value() <<  std::endl;
            auto ret3 = mstoi(str3);
            std::cout << typeid(decltype(ret3.value())).name() << " : " <<  ret3.value_or(-99) << std::endl;
        }
    }

} // namespace test

int main() {
    test::v3::test02();
    


    return 0;
}