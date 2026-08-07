#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

namespace test{

    class Log {
        friend class LogAnalyzer;
        friend std::ostream& operator<<(std::ostream& out, const Log& log);
    public:
        Log() : ip_{0} {}
        Log(std::string log) {
            set(log);
        }
        Log(int ip[4], const std::string& url, const std::string& time) {
            for (int i = 0; i < 4; ++i) {
                ip_[i] = ip[i];
            }                
            url_ = url;
            time_ = time;
        }
    public:
        bool operator<(const Log& other) const {
            unsigned op1 = this->encode();
            unsigned op2 = other.encode();
            return std::tie(op1, this->url_, this->time_) < std::tie(op2, other.url_, other.time_);
        }
        bool operator==(const Log& other) const {
            if (this->ip_[0] == other.ip_[0]
            && this->ip_[1] == other.ip_[1]
            && this->ip_[2] == other.ip_[2]
            && this->ip_[3] == other.ip_[3]
            && this->url_ == other.url_
            && this->time_ == other.time_)
                return true;
            else
                return false;
        }
        bool operator>(const Log& other) const {
            return !this->operator<(other) && !this->operator==(other);
        }
    public:
        const std::string get_ip() const {
            std::ostringstream oss;
            oss << ip_[0] << '.' << ip_[1] << '.' << ip_[2] << '.' << ip_[3];
            return oss.str();
        }
        const std::string get_url() const {
            return url_;
        }
        const std::string get_time() const {
            return time_;
        }
    private:
        unsigned encode() const {
            return (ip_[0] << 24) | (ip_[1] << 16) | (ip_[2] << 8) | (ip_[3]);
        }
        void set(const std::string& log) {
            size_t dot1 = log.find('.');
            size_t dot2 = log.find('.', dot1 + 1);
            size_t dot3 = log.find('.', dot2 + 1);
            size_t sep1 = log.find(' ', dot3 + 1);
            size_t sep2 = log.find(' ', sep1 + 1);
            ip_[0] = std::stoi(log.substr(0,dot1));
            ip_[1] = std::stoi(log.substr(dot1 + 1, dot2 - dot1 - 1));
            ip_[2] = std::stoi(log.substr(dot2 + 1, dot3 - dot2 - 1));
            ip_[3] = std::stoi(log.substr(dot3 + 1, sep1 - dot3 - 1));
            url_ = log.substr(sep1 + 1, sep2 - sep1 - 1);
            time_ = log.substr(sep2 + 1, log.size() - sep2 - 1);
        }
    private:            
        int ip_[4];
        std::string url_;
        std::string time_;
    };
    std::istream& operator>>(std::istream& in, Log& log) {
        std::string ip, url, time;
        in >> ip >> url >> time;
        if (in)
            log = Log(ip + ' '+ url + ' ' +  time);
        return in;
    }
    std::ostream& operator<<(std::ostream& out, const Log& log) {
        out << log.get_ip() << ' '
        << log.url_ << ' ' << log.time_;
        return out;
    }
    class LogAnalyzer {
    public:
        LogAnalyzer();
        LogAnalyzer(std::vector<std::string>& data);
    public:
        //LogAnalyzer(const LogAnalyzer& other);
        //LogAnalyzer& operator=(const LogAnalyzer& other);
        //LogAnalyzer(LogAnalyzer&& other);
        //LogAnalyzer& operator=(LogAnalyzer&& other);
    public:
        auto begin();
        auto end();
        size_t size() const ;
        void show() const ;
        void show_size() const ;
        void show_data() const ;
        void show_cal() const ;
        void show_index() const ;
    public:
        size_t count(const std::string& ip, const std::string& url);
        size_t count(const std::string& ip);
        std::vector<Log> find_ip(const std::string& ip) const ;
        std::vector<Log> find_url(const std::string& url) const ;
        std::vector<Log> find_url_index(const std::string& url) const ;
        bool insert(Log log);
        void analyze(std::vector<std::string>& data);
        bool read(std::istream& stream, size_t times);
    private:
        size_t size_;
        std::set<Log> data_;
        std::multimap<std::string, decltype(data_.begin())> index_;
        std::map<std::string, size_t> cal_;
    }; // LogAnalyzer
    LogAnalyzer::LogAnalyzer() : size_(0){}
    
    LogAnalyzer::LogAnalyzer(std::vector<std::string>& data) : size_(0) {
        this->analyze(data);
    }
    size_t LogAnalyzer::count(const std::string& ip) {
        auto ret = this->cal_.find(ip);
        if (ret == cal_.end())
            return 0;
        else
            return ret->second;
    }
    size_t LogAnalyzer::count(const std::string& ip, const std::string& url) {
        auto first = this->data_.begin();
        auto last  = this->data_.end();
        auto range = std::equal_range(first, last, Log(ip + ' ' + url + ' ' + "time"),
                 [](const Log &first, const Log &second) -> bool {
                    if (first.encode() < second.encode())
                        return true;
                    else if (first.encode() == second.encode() &&
                            first.url_ < second.url_)
                        return true;
                    else
                        return false;
                 });
        auto it = range.first;
        size_t cnt = 0;
        while (it != range.second) {
            ++cnt;
            ++it;
        }
        return cnt;
    }
    std::vector<Log> LogAnalyzer::find_ip(const std::string& ip) const {
        auto range = std::equal_range(data_.begin(), data_.end(), Log(ip + " / time"), [](const Log& first, const Log& second) -> bool { return first.encode() < second.encode();});
        std::vector<Log> ret;
        auto it = range.first;
        while (it != range.second) {
            ret.push_back(*it);
            ++it;
        }
        return ret;
    }
    std::vector<Log> LogAnalyzer::find_url(const std::string& url) const {
        std::vector<Log> ret;
        for (const auto& trans : this->data_) {
            if (trans.get_url() == url)
                ret.push_back(trans);
        }
        return ret;
    }
    std::vector<Log> LogAnalyzer::find_url_index(const std::string& url) const {
        auto range = std::equal_range(index_.begin(), index_.end(), std::pair<std::string, std::set<Log>::iterator>{url,data_.begin()}, [](std::pair<std::string, std::set<Log>::iterator> a, decltype(a) b) {
        if (a.first < b.first)
            return true;
        else
            return false;
        });
        std::vector<Log> ret;
        while (range.first != range.second) {
            ret.push_back(*(range.first->second));
            ++range.first;
        }
        return ret;
    }
    void LogAnalyzer::analyze(std::vector<std::string>& data) {
        for (auto& trans : data) {
            Log temp(trans);
            auto it = data_.insert(temp);                        
            if (it.second) {
                index_.insert({it.first->get_url(), it.first});
                cal_[temp.get_ip()] += 1;
                ++size_;
            }
        }
    }
    bool LogAnalyzer::read(std::istream& stream, size_t times = 1) {
        // auto read @times Logs from @stream
        // when @times is not set, read once
        Log temp;
        for (size_t i = 0; stream && i < times; ++i) {
            stream >> temp;
            if (stream)
                this->insert(temp);
        }
        return bool(stream);
    }
    size_t LogAnalyzer::size() const {
        return this->size_;
    }
    auto LogAnalyzer::begin() {
        return this->data_.begin();
    }
    auto LogAnalyzer::end() {
        return this->data_.end();
    }
    bool LogAnalyzer::insert(Log log) {
        auto ret = data_.insert(log);
        if (ret.second == true) {
            index_.insert(std::pair{ret.first->get_url(), ret.first});
            cal_[log.get_ip()] += 1;
            ++size_;
        }
        return ret.second;
    }
    void LogAnalyzer::show() const {
        show_size();
        std::cout << " --- data --- " << std::endl;
        show_data();
        std::cout << " --- calculation --- " << std::endl;
        show_cal();
    }
    void LogAnalyzer::show_size() const {
        std::cout << " --- size : " << this->size_ << " --- " << std::endl;
    }
    void LogAnalyzer::show_data() const {
        for (auto& trans : this->data_) {
            std::cout << trans << std::endl;
        }
    }
    void LogAnalyzer::show_cal() const {
        for (auto& trans : this->cal_) {
            std::cout << trans.first << " : " << trans.second << " times"<< std::endl;
        }
    }
    void LogAnalyzer::show_index() const {
        for (auto& trans: this->index_) {
            std::cout << *(trans.second) << std::endl;
        }
    }
    // --- test ---
    void test01();
    void test02();
    void test03();
    void test04();
    void test05();
    
} // namespace test

int main() {
    test::test05();


    return 0;
}

namespace test{
    
    void test01() {
        std::string log, temp;
        std::cout << "Enter one log : " << std::endl;
        std::cin >> log;
        log += ' ';
        std::cin >> temp;
        log += temp;
        log += ' ';
        std::cin >> temp;
        std::cout << temp << std::endl;
        log += temp;

        std::cout << "output" << std::endl;
        Log l1(log);
        std::cout << l1 << std::endl;
    }
    void test02() {
        std::string log, temp;
        while (std::cin >> temp) {
            if (!log.empty())
                log += ' ';
            log += temp;
        }
        auto dot1 = log.find('.');
        auto dot2 = log.find('.', dot1 + 1);
        auto dot3 = log.find('.', dot2 + 1);
        auto sep1 = log.find(' ', dot3 + 1);
        auto sep2 = log.find(' ', sep1 + 1);
        std::cout << log.substr(0,dot1) << std::endl;
        std::cout << log.substr(dot1 + 1, dot2 - dot1 - 1) << std::endl;
        std::cout << log.substr(dot2 + 1, dot3 - dot2 - 1) << std::endl;
        std::cout << log.substr(dot3 + 1, sep1 - dot3 - 1) << std::endl;
        std::cout << log.substr(sep1 + 1, sep2 - sep1 - 1) << std::endl;
        std::cout << log.substr(sep2 + 1, log.size() - sep2 - 1) << std::endl;       
    }
    
    void test03() {
        Log b("192.168.1.10 /index.html 2026-07-24-08:00:01");
        Log a("10.0.0.5 /api/login 2026-07-24-08:00:03");
        std::swap(a,b);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        if (a < b)
            std::cout << " < " << std::endl;
        else if (a > b)
            std::cout << " > " << std::endl;
        else if (a == b)
            std::cout << " = " << std::endl;
    }
    
    void test04() {
        LogAnalyzer la;
        while (la.read(std::cin)) {}
        la.show();
        std::cout << "la.count : " << la.count("10.0.0.5", "/api/login") << std::endl;
        std::cout << " --- la.find(\"10.0.0.5\") and show --- " << std::endl;
        std::vector<Log> logs = la.find_ip("10.0.0.5");
        for (const auto& trans : logs) {
            std::cout << trans << std::endl;
        }
    }
    
    void test05() {
        LogAnalyzer la;
        while (la.read(std::cin)) {};
        la.show();
        std::cout << " --- find_url() --- " << std::endl;
        std::vector<Log> logs = la.find_url("/api/login");
        for (const auto & trans : logs) {
            std::cout << trans << std::endl;
        }
        std::cout << " --- find_url_index() --- " << std::endl;
        logs = la.find_url_index("/api/login");
        for (const auto& trans : logs) {
            std::cout << trans << std::endl;
        }
        std::cout << " --- show_index() --- " << std::endl;
        la.show_index();
    }
} // namespace test