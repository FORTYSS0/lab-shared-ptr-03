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
  int val = 5, val2 = 30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spoz(&val2);
  std::cout<<sp1.use_count()<<std::endl;
  Values val1;
  val1.val=20;
  SharedPtr<Values> sp5(&val1);
  std::cout<< sp5->val<<std::endl;
  std::cout<<*sp1<<" "<<*sp2<<" "<<*sp3<<" "<<*spoz<<std::endl;
  std::cout<<sp1.get()<<" "<<sp2.get()<<" "<<sp3.get()<<" "<<spoz.get()<<std::endl;
  std::cout<<(sp)<<" "<<(sp1)<<std::endl;
  sp1.reset();
  sp2.reset(&val2);
  std::cout<<(sp1)<<" "<<*sp2<<std::endl;
  std::cout<<*sp3<<" "<<*spoz<<std::endl;
  sp3.swap(spoz);
  std::cout<<*sp3<<" "<<*spoz<<std::endl;
  EXPECT_TRUE(true);
  EXPECT_EQ((sp),0);
}
TEST(Test, Zerro) {
  SharedPtr<int> sp;
  EXPECT_EQ((sp),0);
}
TEST(Test, UseCount) {
  int val = 5;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  EXPECT_EQ(sp1.use_count(),3);
}
TEST(Test, Clas_Strelka) {
  class Values{
   public:
    int val;
  };
  Values val1;
  val1.val=20;
  SharedPtr<Values> sp5(&val1);
  EXPECT_EQ(sp5->val,20);
}
TEST(Test, Zvezda) {
  int val = 5, val2 = 30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spoz(&val2);
  std::stringstream str;
  str<<*sp1<<" "<<*sp2<<" "<<*sp3<<" "<<*spoz;
  std::string stroka = "5 5 5 30";
  EXPECT_EQ(str.str(), stroka);
}
TEST(Test, Get) {
  int val = 5, val2 = 30;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spoz(&val2);
  std::stringstream str, str2;
  str<<*sp1.get()<<" "<<*sp2.get()<<" "<<*sp3.get()<<" "<<*spoz.get();
  std::string stroka = "5 5 5 30";
  EXPECT_EQ(str.str(), stroka);
}
