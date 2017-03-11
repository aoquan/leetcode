#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void sort(vector<int>& a,int l,int h){
        if(l>=h) return;
        int m = adjust(a,l,h);
        sort(a,l,m-1);
        sort(a,m+1,h);
        return ;
    }
    int adjust(vector<int>& a,int l,int h){
        int tmp = a[l];
        while(l<h){
            while(a[h]>=tmp&&l<h){
                h--;
            }
            if(h>l){
                a[l++] =a[h];
            }
            while(a[l]<tmp&&l<h){
                l++;
            }
            if(h>l){
                a[h--]=a[l];
            }
        }
        a[l]=tmp;
        return l;
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
    s.sort(a,0,a.size()-1);
    s.show(a);
    
}
