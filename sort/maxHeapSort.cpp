#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> sort(vector<int>& a){
        int len = a.size();
        int i;
        for(i=len/2-1;i>=0;i--){
            maxHeapDown(a,i,len-1);
        }
        show(a);
        for(i=len-1;i>0;i--){
            swap(a[i],a[0]);
            maxHeapDown(a,0,i-1);
        }
        return a;
    }
    void maxHeapDown(vector<int>& a,int start,int end){
        for(int l = start*2+1;l<=end;start = l,l=l*2+1){
            if(a[l]<a[l+1]&&l<end){
                l++;
            }
            if(a[start]>a[l]){
                break;
            }
            swap(a[start],a[l]);
        }
    }
    void show(vector<int> a){
        vector<int>::iterator it;
        for(it=a.begin();it!=a.end();it++){
            cout<<*it<<" "<<ends;
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
