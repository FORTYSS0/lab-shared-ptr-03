// Copyright 2021 by FORTYSS

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <string>

template <typename T>
class SharedPtr {
 public:
  SharedPtr();
  SharedPtr(T* ptr);
  SharedPtr(const SharedPtr& r);
  SharedPtr(SharedPtr&& r);
  ~SharedPtr();
  auto operator=(const SharedPtr& r) -> SharedPtr&;
  auto operator=(SharedPtr&& r) -> SharedPtr&;

  // проверяет, указывает ли указатель на объект
  operator bool() const;
  auto operator*() const -> T&;
  auto operator->() const -> T*;

  auto get() -> T*;
  void reset();
  void reset(T* ptr);
  void swap(SharedPtr& r);
  // возвращает количество объектов SharedPtr, которые ссылаются на тот же управляемый объект
  auto use_count() const -> size_t;
};

#endif // INCLUDE_HEADER_HPP_
