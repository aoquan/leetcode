#include<iostream>
#include<map>
#include<set>
#include<vector>
typedef int (*PF)(int a,int b);
using namespace std;
int func1(int a,int b){
    return a+b;
}
int main(){
    map<int,int> m ;
    pair<int,int>a;
    a.first = 5,a.second=6;
    m.insert(make_pair(1,2));
    m.insert(make_pair(3,4));
    m.insert(a);
    cout<<(m.find(3))->second<<endl;
    m.erase(m.find(3));
    map<int,int>::iterator mit = m.begin();
    while(mit!=m.end()){
        cout<<mit->first<<" "<<mit->second<<endl;
        mit++;
    }

    vector<int> v;
    for(int i=0;i<20;i++){
        v.push_back(i%10);
    }
    set<int> s(v.begin(),v.end());
    cout<<v.size()<<endl;
    cout<<s.size()<<endl;

    cout<<"########################"<<endl;
    multimap<int,int> mm;
    mm.insert(make_pair(1,1));
    mm.insert(make_pair(2,1));
    mm.insert(make_pair(2,2));
    mm.insert(make_pair(2,3));
    multimap<int,int>::iterator mulIt;
    multimap<int,int>::iterator beg;
    multimap<int,int>::iterator end;
    mulIt=mm.find(2);
    int count=mm.count(2);
    for(int j=0;j<count;j++,mulIt++){
        cout<<mulIt->first<<" "<<mulIt->second<<endl;
    }
    cout<<"########################"<<endl;
    beg = mm.lower_bound(2);
    end = mm.upper_bound(2);
    while(beg!=end){
        cout<<beg->first<<" "<<beg->second<<endl;
        beg++;
    }
    cout<<"########################"<<endl;
    pair<multimap<int,int>::iterator,multimap<int,int>::iterator> pa = mm.equal_range(2);
    while(pa.first!=pa.second){
        cout<<(pa.first)->first<<" "<<(pa.first)->second<<endl;
        pa.first++;
    }


    return 0;
}
