//
// Created by ninjachacha on 2/16/25.
//
#include<bits/stdc++.h>
using namespace std;
template<class T,int N>
class Array{
  int size{N};
  T values[N];
  friend ostream& operator<<(ostream& os, const Array<T,N>& arr){
    os<<"[";
    for(const auto &val:arr.values){
      os<<val<<" ";
    }
    os<<"]"<<endl;
    return os;
  }
  public:
    Array()=default;
    Array(T val)
    {
      for(auto &item:values)
        item=val;
    }
    void fill(T val){
      for(auto &item:values)
        item=val;
    }
    int getSize() const{
      return size;
    }
    T &operator[](int index) {
      return values[index];
    }
};

int main()
{
  Array<int,5> nums;
  cout<<"The size is: "<<nums.getSize()<<endl;
  cout<<nums<<endl;
  nums.fill(0);
  cout<<"The size is: "<<nums.getSize()<<endl;
  cout<<nums<<endl;
  nums.fill(10);
  cout<<nums<<endl;
  nums[0]=1000;
  nums[3]=1000;
  cout<<nums<<endl;
  Array<int,100> nums2{1};
  cout<<"The size is: "<<nums2.getSize()<<endl;
  cout<<nums2<<endl;
  Array<string,10> str(string{"Suraj Jha,"});
  cout<<"The size is: "<<str.getSize()<<endl;
  cout<<str<<endl;
  str[1]=string{"is Boss,"};
  cout<<str<<endl;
  str.fill(string{"X,"});
  cout<<str<<endl;
  return 0;
}