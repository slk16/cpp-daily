#include <iostream>
#include <string>
namespace abo{
    namespace v1 {
        class Agent {
        public:
            Agent(){};
            Agent(const std::string& name_) : money_(0),food_(0){}

        private:
            int money_;
            int food_;
            std::string name_;
        }
    }
}

int main() {
    



    return 0;
}