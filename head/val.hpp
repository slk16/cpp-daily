#pragma once
#ifndef VALHPP
#define VALHPP 1
#include <utility>
namespace slk{
    struct copy_{};
    template <typename T>
    class Val{
        public:
            Val() : val_{} {}
            void set_val(T val) {
                this->val_ = val;
            }
            T get_val()const {
                return this->val_;
            }
        public:
            Val(const Val& other) : val_(other.val_) {}
            Val& operator=(const Val& other) { val_ = other.val_; return *this; }
            Val(Val&& other) : val_(std::move(other.val_)) { other.val_ = Val<T>{};}
            Val& operator=(Val&& other) { if (this == &other) return *this;val_ = std::move(other.val_);other.val_ = Val<T>{};return *this;}
            ~Val() = default;
        public:
            template <typename... Args>
            Val(Args... args) : val_(args...) {

            }
        private:
            T val_;
    }; 
}
#endif