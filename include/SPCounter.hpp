// Created by FORTYSS on 17.01.2021.

#ifndef TEMPLATE_SPCOUNTER_HPP
#define TEMPLATE_SPCOUNTER_HPP

#include "SharedPtr.hpp"

template<typename T>
class SPCounter {
 public:
  explicit SPCounter(T *p) noexcept : count(1), ptr(p) {}
  void add() noexcept {
    ++count;
  }
  void release() noexcept {
    if (!--count) {
      ptr = nullptr;
      delete this;
    }
  }
  size_t use_count() const noexcept {
    return count.load();
  }
 private:
  std::atomic<size_t> count;
  T* ptr;
};

#endif  // TEMPLATE_SPCOUNTER_HPP
