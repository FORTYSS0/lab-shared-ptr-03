// Created by FORTYSS on 17.01.2021.

#ifndef TEMPLATE_SPCOUNTER_HPP
#define TEMPLATE_SPCOUNTER_HPP

#include "SharedPtr.hpp"

template<typename T>
class SPCounter {
 public:
  SPCounter(T* p) noexcept{
    if(p != nullptr) {
      count = 1;
      ptr = p;
    } else {
      count =0;
      ptr = p;
    }
  }
  void add() noexcept { ++count; }
  void release() noexcept {
    if (!--count) {
      ptr = nullptr;
      delete this;
    }
  }
  auto use_count() const noexcept -> size_t { return count.load(); }
  void unadd(){count--;}
  void add(size_t c){
    count = c;
  }
 private:
  std::atomic<size_t> count;
  T* ptr;
};

#endif  // TEMPLATE_SPCOUNTER_HPP
