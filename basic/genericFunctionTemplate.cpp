//
// Created by ninjachacha on 2/15/25.
//
#include<bits/stdc++.h>

#include <utility>
using namespace std;
class player{
     string name;
     int score1,score2;
     public:
       player():player("",0,0) {}
       player(string  name, const int score1, const int score2):name(std::move(name)),score1(score1),score2(score2){}
       bool operator>(const player &p)const{
         return score1>p.score1;
       }
       friend ostream& operator<<(ostream& os, const player &p)
       {
         os<<"name: "<<p.name<<endl;
         os<<"score1: "<<p.score1<<endl;
         os<<"score2: "<<p.score2<<endl;
         return os;
       }
 };
 template<class T>
 T Max(T a, T b){
   return a>b?a:b;
 }
int main(){
  cout<<Max('A','C')<<endl;
  cout<<Max(100,200)<<endl;
  cout<<Max("65","67")<<endl;
  const player p1{"Hero",100,20},p2{"Enemy",99,3};
  cout<<Max(p1,p2)<<endl;
}