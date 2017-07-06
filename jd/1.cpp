#include <iostream>
using namespace std;
int my_xor(string s1,string s2){
    int re=0,i;
    for(i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            re = re*2 + 1;
        }
        else{
            re = re*2;
        }
    }
    return re;
}


int main(){
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;
    cout<<my_xor(s1,s2)<<endl;
    return 0;
}
