#include <iostream>
using namespace std;
int rock(int n,int k){
    if(n==k) return 1;
    int a1 = k;
    int a2 = k+1;
    int count=0;
    while(n>k){
        if(count%2==0){
            n -= a1;
        }
        else{
            n -= a2;
        }
        count++;
    }
    if(n==k){
        if(count%2==0){
            count++;
        }   
    }

    return count;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<rock(n,k)<<endl;
    return 0;
}

