#include <iostream>
#include <set>
using namespace std;
int main(){
    set<long long> st;
    long long uid;
    cin>>uid;
    while(uid!=0){
        st.insert(uid);
        cin>>uid;
    }
    cout<<st.size();
    return 0;
}
