//
// Created by ninjachacha on 3/2/25.
//
#include<iostream>
#include <utility>
#include<vector>
#include<algorithm>
using namespace std;

class Person {
    friend ostream& operator<<(ostream&, const Person&);
    string name;
    int age{};
    public:
    Person()=default;
    Person(string name, const int age) : name(move(name)), age(age) {}
    bool operator<(const Person& person) const {
        return this->age < person.age;
    }
};

ostream& operator<<(ostream& cout, const Person& person) {
    cout<<person.name<<" : "<<person.age;
    return cout;
}

void display(const vector<int>& vec) {
    cout<<"[";
    for_each(vec.begin(), vec.end(), [](const int i){ cout<<i<<" ";});
    cout<<"]"<<endl;
}

template<typename T>
void display1(const vector<T>& vec) {
  cout<<"[";
  for(const auto& i:vec)
      cout<<i<<" ";
  cout<<"]"<<endl;
}

void display3(const vector<pair<int,string>>& vec)
{
    cout<<"[";
    for (const auto& [fst, snd]:vec)
        cout<<fst<<" : "<<snd<<" ";
    cout<<"]"<<endl;
}

void test0()
{
    const vector<int> vec1{1,2,3,4,5};
    const vector<int> vec2={10,20,30,40,50};
    vector<int> vec3;
    vec3={100,200,300,400,500};
    cout<<"vec1: "; display1(vec1);
    cout<<"vec2: "; display(vec2);
    cout<<"vec3: "; display(vec3);
    try
    {
        //vec1.at(10);
        cout<<"vec1.front(): "<<vec1.front()<<" vec1.back(): "<<vec1.back()<<endl;
        cout<<"vec2.front(): "<<vec2.front()<<" vec2.back(): "<<vec2.back()<<endl;
        cout<<"vec3.front(): "<<vec3.front()<<" vec3.back(): "<<vec3.back()<<endl;
    }
    catch(...)
    {
        cout<<"exception"<<endl;
    }
    vector<Person> vec4;
    const Person p1{"Suraj Jha",22};
    Person p2("Dinesh", 25);
    vec4.push_back(p1);
    vec4.push_back(p2);
    vec4.push_back(Person{"Sagar Jha",20});
    vec4.push_back(Person("Aman Gupta",35));
    vec4.push_back({"Virat Kohli",18});
    vec4.emplace_back("Rohit Sharma",45);
    display1(vec4);
    vec4.pop_back();
    display1(vec4);
}

void test1() {
    cout<<"===== test1 ====="<<endl;
  vector<int> vec{1,2,3,4,5};
  cout<<"vec: "; display(vec);
  cout<<"vec.size(): "<<vec.size()<<endl;
  cout<<"vec.capacity(): "<<vec.capacity()<<endl;
  cout<<"vec.max_size(): "<<vec.max_size()<<endl;
  vec.push_back(6);
  cout<<"\nvec: "; display(vec);
  cout<<"vec.size(): "<<vec.size()<<endl;
  cout<<"vec.capacity(): "<<vec.capacity()<<endl;
  cout<<"vec.max_size(): "<<vec.max_size()<<endl;
  vec.shrink_to_fit();
  cout<<"\nvec: "; display(vec);
  cout<<"vec.size(): "<<vec.size()<<endl;
  cout<<"vec.capacity(): "<<vec.capacity()<<endl;
  cout<<"vec.max_size(): "<<vec.max_size()<<endl;
  vec.reserve(100);
  cout<<"\nvec: "; display(vec);
  cout<<"vec.size(): "<<vec.size()<<endl;
  cout<<"vec.capacity(): "<<vec.capacity()<<endl;
  cout<<"vec.max_size(): "<<vec.max_size()<<endl;
  vec.clear();
  cout<<"\nvec: "; display(vec);
  cout<<"vec.size(): "<<vec.size()<<endl;
  cout<<"vec.capacity(): "<<vec.capacity()<<endl;
  cout<<"vec.max_size(): "<<vec.max_size()<<endl;
}

void test2()
{
    cout<<"===== test2 ====="<<endl;
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    cout<<"vec: "; display(vec);
    cout<<"vec.size(): "<<vec.size()<<endl;
    cout<<"vec.capacity(): "<<vec.capacity()<<endl;
    cout<<"vec.max_size(): "<<vec.max_size()<<endl;
    vec.erase(vec.begin(),vec.begin()+2);
    cout<<"vec: "; display(vec);
    cout<<"vec.size(): "<<vec.size()<<endl;
    cout<<"vec.capacity(): "<<vec.capacity()<<endl;
    vec={1,2,3,4,5,6,7,8,9,10};
    auto it=vec.begin();
    while (it!=vec.end())
    {
        if (*it%2==0)
            vec.erase(it);
        else
            ++it;
    }
    cout<<"vec: "; display(vec);
}

void test3()
{
    cout<<"===== test3 ====="<<endl;
    vector<int> vec1{1,2,3,4,5}, vec2{10,20};
    cout<<"vec1: "; display1(vec1);
    cout<<"vec2: "; display1(vec2);
    copy(vec1.begin(), vec1.end(), back_inserter(vec2));
    cout<<"vec1: "; display1(vec1);
    cout<<"vec2: "; display1(vec2);
    vec1={1,2,3,4,5,6,7,8,9,10};
    vec2={10,20};
    copy_if(vec1.begin(), vec1.end(), back_inserter(vec2), [](int i){ return i%2==0; });
    cout<<"vec1: "; display1(vec1);
    cout<<"vec2: "; display1(vec2);
}

void test4()
{
    cout<<"===== test4 ====="<<endl;
    vector<int> vec1{1,2,3,4,5}, vec2{10,20,30,40,50};
    cout<<"vec1: "; display1(vec1);
    cout<<"vec2: "; display1(vec2);
    vector<int> vec3;
    transform(vec1.begin(),vec1.end(),vec2.begin(),back_inserter(vec3),[](int x,int y){ return x*y;});
    cout<<"After using transform() with 5 parameters: "<<endl;
    cout<<"vec3: "; display(vec3);
}

void test5()
{
    cout<<"===== test5 ====="<<endl;
    vector<pair<int,string>> vec={{1,"one"}, {2,"two"}, {3,"three"},{4,"four"}, {5,"five"}};
    sort(vec.begin(),vec.end());
    cout<<"Sorting based on int: "; display3(vec);
    sort(vec.begin(),vec.end(),[](const pair<int,string>& a,const pair<int,string>& b){ return a.second<b.second;});
    cout<<"sorting based on string: "; display3(vec);
}

int main(int argc, char const *argv[]) {
    test0();    cout<<endl;
    test1();    cout<<endl;
    test2();    cout<<endl;
    test3();    cout<<endl;
    test4();    cout<<endl;
    test5();    cout<<endl;
    return 0;
}