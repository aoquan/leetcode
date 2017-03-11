#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> sort(vector<int> a){
        int i,j;
        int len = a.size();
        for(i=1;i<len;i++){
            for(j=i;j>0 && a[j]<a[j-1];j--){
                swap(a[j],a[j-1]);
            }
        }
        return a;
    }
    void show(vector<int> a){
        vector<int>::iterator it;
        for(it=a.begin();it!=a.end();it++){
            cout<<*it<<ends;
        }
        cout<<endl;
    }  
};
int main(){
    int x;
    vector<int> a,b;
    Solution s;
    while(cin>>x){
        a.push_back(x);
    }
    s.show(a);
    b=s.sort(a);
    s.show(b);
    
}
