#include <iostream>
using namespace std;

int c[8], n=4, cnt=0;
void print(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(j == c[i]) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void search(int r){
    if(r == n){
        print();
        cnt++;
        return ;
    }
    int i;
    for(i = 0; i < n; i++){
        c[r] = i;
        bool ok = true;
        int j;
        for(j = 0; j < r; j++){
            if(c[r] == c[j] || r-j == c[r] - c[j] || j-r == c[r] - c[j]){
                ok = false;
                break;
            }
        }
        if(ok) search(r+1);
    }
}
int main(){
    search(0);
    cout<<cnt<<endl;
    return 0;
}
