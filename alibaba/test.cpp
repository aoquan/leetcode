#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
set<int> GetUnion(set<int>& v1, set<int>& v2){
    set<int> re;
    set<int>::iterator it1,it2;
    for(it1=v1.begin();it1!=v1.end();it1++){
        for(it2=v2.begin();it2!=v2.end();it2++){
            re.insert(*it1+*it2);
        }
    }
    return re;
}

set<int> GetAbs(set<int>& v1, set<int>& v2){
    set<int> re;
    set<int>::iterator it1,it2;
    for(it1=v1.begin();it1!=v1.end();it1++){
        for(it2=v2.begin();it2!=v2.end();it2++){
            re.insert(abs(*it1-*it2));
        }
    }
    return re;
}

int main(){
    int n,i,tmp;
    set<int> st;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>tmp;
        st.insert(tmp);
    }

    set<int> sunion = GetUnion(st,st);
    set<int> sabs = GetAbs(st,st);
    set<int> ababs = GetAbs(sunion,sabs);

    int minvalue = *(ababs.begin()), maxvalue = *(ababs.begin());
    set<int>::iterator it1;
    for(it1=ababs.begin();it1!=ababs.end();it1++){
        if(minvalue > *it1) minvalue = *it1;
        if(maxvalue < *it1) maxvalue = *it1;
    }
    int size = ababs.size();
    cout<< minvalue<<endl;
    cout<< maxvalue<<endl;
    cout<< size<<endl;

    cout<< minvalue + maxvalue + size <<endl;
}




