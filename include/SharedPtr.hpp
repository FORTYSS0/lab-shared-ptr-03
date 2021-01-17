// Copyright 2021 by FORTYSS

#ifndef INCLUDE_SHAREDPTR_HPP_
#define INCLUDE_SHAREDPTR_HPP_

#include <string>
#include <memory>
#include <utility>
#include <atomic>
#include "SPCounter.hpp"

template <typename T>
class SharedPtr {
 public:
  SharedPtr() noexcept : ptr(nullptr), counter(nullptr){}
  SharedPtr(T* ptr) {
    std::unique_ptr<T> p(ptr);
    counter = new SPCounter<T>(p.get());
    ptr=p.release();
  }
  SharedPtr(const SharedPtr& r) noexcept {
    ptr = r.ptr;
    counter = r.counter;
    counter->add();
  }
  SharedPtr(SharedPtr&& r) {
    std::swap(ptr, r.ptr)
    std::swap(counter, r.counter)
  }
  ~SharedPtr() {
    counter->release();
  }
  auto operator=(const SharedPtr& r) -> SharedPtr& {
    counter->realease();
    ptr = r.ptr;
    counter = r.counter;
    counter->add();
    return  *this;
  }
  auto operator=(SharedPtr&& r) -> SharedPtr& {
    counter->release();
    ptr = std::move(r.ptr);
    counter = std::move(r.counter);
    return this;
  }

  // проверяет, указывает ли указатель на объект
  operator bool() const {
    return (ptr != nullptr);
  }
  auto operator*() const -> T& {
    return *ptr
  }
  auto operator->() const -> T* {
    return ptr;
  }

  auto get() -> T* {
    return ptr;
  }
  void reset() {
    ptr = nullptr;
    counter = nullptr;
  }
  void reset(T* ptr) {
    std::unique_ptr<T> p(ptr);
    counter = new SPCounter<T>(p.get());
    ptr=p.release();
  }
  void reset(const SharedPtr<T>& r) {
    this->ptr = r.ptr;
    counter = r.counter;
    counter->add();
  }
  void reset(const SharedPtr<T>&& r) {
    counter->release();
    ptr = std::move(r.ptr);
    counter = std::move(r.counter);
    return this;
  }
  void swap(SharedPtr& r) {
    std::swap(r.ptr, ptr)
    std::swap(r.counter, counter);
  }
  void swap(SharedPtr& r, SharedPtr& r1) {
    std::swap(r.ptr, r1.ptr)
    std::swap(r.counter, r1.counter);
  }
  // возвращает количество объектов SharedPtr, которые ссылаются на тот же управляемый объект
  auto use_count() const -> size_t {
    return (counter!= nullptr) ? counter->use_count(): 0;
  }

 private:
  T *ptr;
  SPCounter<T> *counter;
};

#endif // INCLUDE_SHAREDPTR_HPP_
