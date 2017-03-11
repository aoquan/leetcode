#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> sort(vector<int> a){
        int i,j,min,pos;
        int len = a.size();
        for(i=0;i<len-1;i++){
            min=a[i];
            pos = i;
            for(j=i;j<len;j++){
                if(a[j]<min){
                    min = a[j];
                    pos = j;
                }
            }
            if(pos!=i)swap(a[i],a[pos]);
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
