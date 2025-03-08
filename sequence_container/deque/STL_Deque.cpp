#include<iostream>
#include<deque>
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

template<typename T>
void display(const deque<T>& d)
{
    cout<<"[";
    for(const auto &ele:d)
        cout<<ele<<" ";
    cout<<"]"<<endl;
}

template<typename T>
void display(const vector<T>& vec)
{
    cout<<"[";
    for_each(vec.begin(),vec.end(),[](const int x){cout<<x<<" ";});
    cout<<"]"<<endl;
}

void display(const deque<pair<int,string>> &dq)
{
    cout<<"[";
    for(const auto& [fs,snd]:dq)
        cout<<fs<<" : "<<snd<<" ";
    cout<<"]"<<endl;
}

void test0() {
    cout<<"===== test0 =====";
    deque<int> dq(5,50);
    deque<string> stooges={string{"Larry"},"Moe",string{"Curly"}};
    cout<<"dq(5,50): ";    display(dq);
    cout<<"dq(5,50) size(): "<<dq.size()<<endl;
    cout<<"dq(5,50) max_size(): "<<dq.max_size()<<endl;
    cout<<"dq(5,50) front(): "<<dq.front()<<endl;
    cout<<"dq(5,50) back(): "<<dq.back()<<endl;
    cout<<"dq(5,50) empty(): "<<dq.empty()<<endl;
    dq.clear();
    cout<<"dq(5,50) clear(): ";    display(dq);
    cout<<"dq(5,50) empty(): "<<dq.empty()<<endl;
    cout<<"\nStooges: ";    display(stooges);
    cout<<"Stooges size(): "<<stooges.size()<<endl;
    cout<<"Stooges max_size(): "<<stooges.max_size()<<endl;
    cout<<"Stooges front(): "<<stooges.front()<<endl;
    cout<<"Stooges back(): "<<stooges.back()<<endl;
    cout<<"Stooges empty(): "<<stooges.empty()<<endl;
    stooges.clear();
    cout<<"Stooges clear(): ";    display(stooges);
    cout<<"Stooges empty(): "<<stooges.empty()<<endl;
}

void test1() {
    cout<<"===== test1 ====="<<endl;
    deque<int> d{1,2,3,4,5};
    cout<<"deque: ";    display(d);
    d[0]=100;   //random access not recommended for Deque
    d.at(1)=200;    //random access not recommended for Deque    
    cout<<"deque: ";    display(d);
}

void test2() {
    cout<<"===== test2 ====="<<endl;
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    deque<int> d;
    cout<<"vec: ";  display(vec);
    cout<<"deque: ";    display(d);
    for(const auto &ele:vec)
    {
        if(ele%2==0)
            d.push_back(ele);
        else
            d.push_front(ele);
    }
    cout<<"deque: ";    display(d);
    d.clear();
    cout<<"clear() deque: ";    display(d);
    copy(vec.begin(),vec.end(),front_inserter(d));
    cout<<"front_inserter() deque: ";   display(d);
    d.clear();
    copy(vec.begin(),vec.end(),back_inserter(d));
    cout<<"back_inserter deque: ";  display(d);
}

void test3() {
    deque<Person> d;
    Person p1{"Suraj",007};
    Person p2("Sagar",420);
    d.push_front(p1);
    d.push_back(p2);
    d.push_front(Person("Messi",10));
    d.push_back(Person{"Ronaldo",7});
    d.push_front({"Dhoni",7});
    d.push_back({"sachin",10});
    d.emplace_front("Rohit",45);
    d.emplace_back("Kohli",18);
    display(d);
    d.pop_back();
    d.pop_front();
    display(d);
}

void test4()
{
    cout<<"===== test4 ====="<<endl;
    deque<string> dq1{"ONE","TWO","THREE","FOUR","FIVE"}, dq2={"TEN","TWENTY","THIRTY","FOURTY","FIFTY"}, dq3;
    cout<<"dq1: ";  display(dq1);
    cout<<"dq2: ";  display(dq2); 
    transform(dq2.begin(),dq2.end(),dq1.begin(),front_inserter(dq3),[](string x,string y){return x+" "+y;});
    cout<<"After using transform() with 5 parameters: "<<endl;
    cout<<"dq3: ";  display(dq3);
}

void test5() {
    cout<<"===== test5 ====="<<endl;
    deque<pair<int,string>> dq={{1,"ONE"},{2,"TWO"},{3,"THREE"},{4,"FOUR"},{5,"FIVE"}};
    sort(dq.begin(),dq.end());
    cout<<"Sorting based on int: ";    display(dq);
    sort(dq.begin(),dq.end(),[](const pair<int,string>& a,const pair<int,string>& b){return a.second<b.second;});
    cout<<"Sorting based on string: ";    display(dq);
}

void test6() {
    cout<<"===== test6 ====="<<endl;
    deque<int> dq1{100,200,300,400,600};
    deque<int> dq2{50,40,30,20,10};
    cout<<"dq1: ";    display(dq1);
    cout<<"dq2: ";    display(dq2);
    dq1.swap(dq2);
    cout<<"Swap\ndq1: ";   display(dq1);
    cout<<"dq2: ";    display(dq2);
    deque<int>::iterator it=find(dq2.begin(),dq2.end(),600);
    dq2.insert(it,500);
    cout<<"dq2.insert(): ";    display(dq2);
    it=find(dq1.begin(),dq1.end(),50);
    dq1.insert(it,dq2.rbegin(),dq2.rend());
    cout<<"vec1.insert(): ";    display(dq1);
}

int main() {
    test0();    cout<<endl;
    test1();    cout<<endl;
    test2();    cout<<endl;
    test3();    cout<<endl;
    test4();    cout<<endl;
    test5();    cout<<endl;
    test6();
    return 0;
}