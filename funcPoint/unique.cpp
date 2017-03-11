#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(3);
    a.push_back(1);
    a.push_back(5);
    a.push_back(2);
    a.push_back(7);
    a.push_back(1);
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
