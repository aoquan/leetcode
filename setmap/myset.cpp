#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    set<int> st;
    int a;
    while(cin>>a){
        if(st.find(a)==st.end()){
            st.insert(a);
        }
    }
    set<int>::iterator it;
    for(it=st.begin();it!=st.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
