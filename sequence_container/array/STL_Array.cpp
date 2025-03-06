//
// Created by ninjachacha on 2/20/25.
//
#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>
using namespace std;
template<class T,int N>
void display(const array<T,N> &arr)
{
  cout<<"[";
  for(const auto &i:arr)
    cout<<i<<" ";
  cout<<"]"<<endl;
};
void test1()
{
  array<int,5> arr1 = {1,2,3,4,5};
  array<int,5> arr2;
  array<string,5> str{string{"Suraj"},string{"Jha"},"is","a","boy"};
  display<int,5>(arr1);
  display<int,5>(arr2);    //print garbage value
  display<string,5>(str);
  arr2={10,20,30,40,50};
  display<int,5>(arr2);
}
void test2()
{
  array<int,5> arr1 = {1,2,3,4,5};
  array<int,5> arr2{10,20,30,40,50};
  arr1.fill(0);    //fills the entire array arr1 with 0
  display<int,5>(arr1);
  display<int,5>(arr2);
}
void test3()
{
  array<int,5> arr1 = {1,2,3,4,5};
  int *ptr=arr1.data();    //ptr holds the address of arr1[0]
  cout<<"*ptr: "<<*ptr<<"  ptr: "<<ptr<<endl;
  *ptr=1000;
  display<int,5>(arr1);
}
void test4()
{
  array<int,5> arr1 = {2,1,4,5,3};
  array<int,5>::iterator min_num=min_element(arr1.begin(),arr1.end());
  auto max_num=max_element(arr1.begin(),arr1.end());
  display<int,5>(arr1);
  cout<<"min: "<<*min_num<<" ,max: "<<*max_num<<endl;
  sort(arr1.begin(),arr1.end());
  display<int,5>(arr1);
}
void test5()
{
  array<int,7> arr1{1,2,3,3,4,5,6};
  auto adjacent=adjacent_find(arr1.begin(),arr1.end());
  if (adjacent!=arr1.end())
    cout<<"adjacent element found: "<<*adjacent<<endl;
  else
    cout<<"No adjacent element found"<<endl;
}
void test6()
{
  array<int,17> arr1 = {1,2,3,1,2,50,60,70,80,3,3,200,300,400,3,3,3};
  display<int,17>(arr1);
  int sum=accumulate(arr1.begin(),arr1.end(),10);
  cout<<"sum is: "<<sum<<endl;
  int cnt=count(arr1.begin(),arr1.end(),3);
  cout<<"Found 3: "<<cnt<<" times."<<endl;
  cnt=count_if(arr1.begin(),arr1.end(),[](int i){return i>10 && i<200;});
  cout<<"Found numbers greater than 10 and less than 200: "<<cnt<<" times."<<endl;
}
void test7()
{
  array<int,10> arr1 = {1,2,3,4,5,6,7,8,9,10};
  cout<<"\narr.size(): "<<arr1.size();
  cout<<"\narr.max_size(): "<<arr1.max_size();
  cout<<"\narr.at(0): "<<arr1.at(0);
  cout<<"\narr.front(): "<<arr1.front();
  cout<<"\narr.back(): "<<arr1.back();
  cout<<"\narr.empty(): "<<arr1.empty()<<endl;
  array<int,10> arr2{10,20,30,40,50};
  arr2.swap(arr1);
  display<int,10>(arr1);
  display<int,10>(arr2);
}
int main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  return 0;
 }