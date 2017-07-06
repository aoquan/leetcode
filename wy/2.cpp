#include<iostream>
#include<set>
using namespace std;
int main(){
    int w,x,y,z;
    cin>>w>>x>>y>>z;
    set<double> st;
    int i,j;
    for(i=w;i<=x;i++){
        for(j=y;j<=z;j++){
            double tmp = i*1.0/j;
            if(st.find(tmp)==st.end()){
                st.insert(tmp);
            }
        }
    }
    cout<<st.size()<<endl;
    return 0;
}
