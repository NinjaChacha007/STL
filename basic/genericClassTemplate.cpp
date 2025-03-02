//
// Created by ninjachacha on 2/15/25.
//
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Item{
  string name;
  T value;
  public:
    Item(): Item("",0){}
    Item(string name, T value):name(name),value(value){}
    string getName()const{
      return name;
    }
    T getValue()const{
      return value;
    }
};
Item it{"Suraj",007};
Item it1{"House",1000.138};
Item it2{"Frank","Boss"};

template<typename T1,typename T2>
struct MyPair{
  T1 first;
  T2 second;
};

int main(){
  Item<int> item1{"Frank",100};
  cout<<item1.getName()<<" "<<item1.getValue()<<endl;
  Item<string> item2{"Suraj","Jha"};
  cout<<item2.getName()<<" "<<item2.getValue()<<endl;
  Item<Item<string> > item3{"Frank",{"C++","Professor"}};
  cout<<item3.getName()<<" ";
  cout<<item3.getValue().getName()<<" ";
  cout<<item3.getValue().getValue()<<endl;
  vector<Item<double>> vec{};
  vec.emplace_back("Larry",100.0);
  vec.emplace_back("Moe", 200.0);
  vec.emplace_back("Curly",300.0);
  vec.emplace_back("Curly",400.0);
  vec.push_back(it1);
  for(auto &item:vec)
    cout<<item.getName()<<" "<<item.getValue()<<endl;
  MyPair<string,int> p1{"Suraj",007};
  MyPair<int,double> p2{124,13.6};
  cout<<p1.first<<" "<<p1.second<<endl;
  cout<<p2.first<<" "<<p2.second<<endl;
  return 0;
}