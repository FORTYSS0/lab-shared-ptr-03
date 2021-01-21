// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "SharedPtr.hpp"

TEST(Example, EmptyTest) {
  class Values{
   public:
    int val;
  };
  SharedPtr<int> sp;
  std::cout<<(sp)<< " " <<sp.use_count() <<std::endl;
  int val = 5;
  SharedPtr<int> sp1 (&val);
 /* SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spoz(new int (10));
  std::cout<<sp1.use_count()<<std::endl;
  Values val1;
  val1.val=20;
  SharedPtr<Values> sp5(&val1);
  std::cout<< sp5->val<<std::endl;
  std::cout<<*sp1<<" "<<*sp2<<" "<<*sp3<<" "<<*spoz<<std::endl;
  std::cout<<sp1.get()<<" "<<sp2.get()<<" "<<sp3.get()<<" "<<spoz.get()<<std::endl;
   std::cout<<(sp)<<" "<<(sp1)<<std::endl;
  sp1.reset();
  sp2.reset(new int(10));
  std::cout<<(sp1)<<" "<<*sp2<<std::endl;
  std::cout<<*sp3<<" "<<*spoz<<std::endl;
  sp3.swap(spoz);
  std::cout<<*sp3<<" "<<*spoz<<std::endl;*/
  EXPECT_TRUE(true);
}
