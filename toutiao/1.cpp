#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> find_same(vector<int> a1,vector<int>a2){
    set<int> st;
    vector<int> re;
    if(a1.size()==0 || a2.size()==0) return re;
    vector<int>::iterator it;
    for(it=a1.begin();it!=a1.end();it++){
        st.insert(*it);
    }
    for(it=a2.begin();it!=a2.end();it++){
        if(st.find(*it)!=st.end()){
            re.push_back(*it);
        }
    }
    return re;
}
int main(){
    int m,n,i,tmp;
    vector<int> a1,a2,re;
    vector<int>::iterator it;
    cin>>m;
    for(i=0;i<m;i++){
        cin>>tmp;
        a1.push_back(tmp);
    }
    cin>>n;
    for(i=0;i<n;i++){
        cin>>tmp;
        a2.push_back(tmp);
    }
    re = find_same(a1,a2);
    for(it=re.begin();it!=re.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}
