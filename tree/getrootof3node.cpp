#include<iostream>
#include<math.h>
using namespace std;
int k,n1,n2,n3;
void search(int l,int h){
    if(l>h) return;
    int m = (l+h)/2;
    if(m == n1 || m == n2 || m == n3){
        cout << m<<endl;
        return;
    }
    if(!((m<n1 && m<n2 && m<n3) || (m>n2 && m > n2 && m > n3))){
        cout<<m<<endl;
        return;
    }
    search(l,m-1);
    search(m+1,h);
}
int main(){
    cin>>k>>n1>>n2>>n3;
    int node = pow(2,k)-1;
    search(1,node);
}
