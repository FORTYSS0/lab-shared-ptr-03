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
  SharedPtr() noexcept {
    ptr =nullptr;
    counter = nullptr;
  }
  explicit SharedPtr(T* r) {
    std::unique_ptr<T> p(r);
    counter = new SPCounter<T>(p.get());
    ptr = p.release();
  }
  SharedPtr(const SharedPtr& r) {
    if(std::is_move_constructible<T>::value){
      ptr = r.ptr;
      counter = r.counter;
      counter->add();
    } else {
      throw std::runtime_error("Not constructible type!");
    }
  }
  SharedPtr(SharedPtr&& r) {
    if(std::is_move_assignable<T>::value) {
      std::swap(ptr, r.ptr);
      std::swap(counter, r.counter);
    } else {
      throw std::runtime_error("Not assignable type!");
    }
  }
  ~SharedPtr() noexcept {
    counter->release();
  }
  auto operator=(const SharedPtr& r) -> SharedPtr& {
    if(std::is_move_constructible<T>::value && &r !=this) {
      counter->realease();
      ptr = r.ptr;
      counter = r.counter;
      counter->add();
    } else if(&r == this) {
      std::cout << "Object equal to this\n";
    } else {
      throw std::runtime_error("Not constructible type!");
    }
    return *this;
  }
  auto operator=(SharedPtr&& r) -> SharedPtr& {
    if(std::is_move_assignable<T>::value && &r !=this) {
      counter->release();
      ptr = r.ptr;
      counter = r.counter;
      counter->add();
    } else if(&r == this) {
      std::cout << "Object equal to this\n";
    } else {
      throw std::runtime_error("Not assignable type!");
    }
    return *this;
  }

  // проверяет, указывает ли указатель на объект
  operator bool() const { return (ptr != nullptr); }
  auto operator*() const -> T& { return *ptr; }
  auto operator->() const -> T* { return ptr; }

  auto get() -> T* { return ptr; }
  void reset() {
    if (counter->use_count() == 1) {
      counter->release();
    } else {
      counter->unadd();
    }
    ptr = nullptr;
    counter = new SPCounter<T>();
  }
  void reset(T* r) {
    if (counter->use_count() == 1) {
      //delete ptr;
      counter->release();
    } else {
      counter->unadd();
    }
    ptr = r;
    if(ptr == nullptr) {
      counter = new SPCounter<T>();
    } else {
      counter->add();
      counter->add(1);
    }

  }
  void swap(SharedPtr& r) {
    std::swap(r.ptr, ptr);
    std::swap(r.counter, counter);
  }
  // возвращает количество объектов SharedPtr, которые ссылаются на тот же управляемый объект
  size_t use_count() {
   if(counter!=nullptr){
     return counter->use_count();
   }else {
     return 0;
   }
  }

 private:
  T *ptr;
  SPCounter<T>* counter;
};

#endif // INCLUDE_SHAREDPTR_HPP_
