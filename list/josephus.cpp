#include<iostream>
#include<fstream>
using namespace std;
struct node{
    int val;
    node *next;
    node(int x):val(x),next(NULL){}
    node():val(0),next(NULL){}
};
class Solution{
    public:
        void josephus(int n,int m ,int k){
            if(n<=0) return ;
            node *tail=NULL,*p,*q;
            for(int i=n;i>=1;i--){
                p = new node(i);
                if(tail==NULL){
                    tail=p;
                    tail->next= tail;
                    continue;
                }
                p->next = tail->next;
                tail->next = p;
            }
            
            p=tail;
            q=tail;
            while(p->val!=k){
                q=p;
                p=p->next;
            }
            p=q;
            while(q!=q->next){
                for(int i=0;i<m;i++){
                    q=p;
                    p=p->next;
                }
                cout<<p->val<<" ";
                q->next=p->next;
                delete p;
                p = q;
            }
            cout<<q->val<<endl;
        }
};
int main(){
    Solution s;
    int n,m,k;
    cin>>n>>m>>k;
    s.josephus(n,m,k);
}
