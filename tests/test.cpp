// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "SharedPtr.hpp"
template<typename T>
class realised{
 public:
  void work() {
    struct Values{
     public:
      int val;
    };
    SharedPtr sp = new SharedPtr<int>();
    std::cout<<sp.use_count();
    int val = 5;
    SharedPtr<int> sp1 (&val);
    SharedPtr<int> sp2(sp1);
    SharedPtr<int> sp3(sp2);
    SharedPtr<int> spoz(new int (10));
    std::cout<<sp1.use_count();
    //Values val1={5};
    //SharedPtr<Values> sp5(val1);
    //std::cout<< sp5->val;
    std::cout<<*sp1<<" "<<*sp2<<" "<<*sp3<<" "<<*spoz;
    std::cout<<sp1.get()<<" "<<sp2.get()<<" "<<sp3.get()<<" "<<spoz.get();
    std::cout<<(sp)<<" "<<(sp1);
    sp1.reset();
    sp2.reset(new int(10));
    std::cout<<(sp1)<<" "<<*sp2;
    std::cout<<*sp3<<" "<<*spoz;
    sp3.swap(spoz);
    std::cout<<*sp3<<" "<<*spoz;




  }
 private:
  T *typ;
};
TEST(Example, EmptyTest) {
  //realised<int> k;
  //k.work();
  SharedPtr sp = new SharedPtr<int>();
  std::cout<<sp.use_count();
  int val = 5;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spoz(new int (10));
  std::cout<<sp1.use_count();
  //Values val1={5};
  //SharedPtr<Values> sp5(val1);
  //std::cout<< sp5->val;
  std::cout<<*sp1<<" "<<*sp2<<" "<<*sp3<<" "<<*spoz;
  std::cout<<sp1.get()<<" "<<sp2.get()<<" "<<sp3.get()<<" "<<spoz.get();
  std::cout<<(sp)<<" "<<(sp1);
  sp1.reset();
  sp2.reset(new int(10));
  std::cout<<(sp1)<<" "<<*sp2;
  std::cout<<*sp3<<" "<<*spoz;
  sp3.swap(spoz);
  std::cout<<*sp3<<" "<<*spoz;
  EXPECT_TRUE(true);
}
