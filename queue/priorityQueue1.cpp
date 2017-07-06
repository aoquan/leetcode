#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class cmp{
    public:
        bool operator()(int a,int b){
            return a>b;
        }
};
int main(){
    priority_queue<int,vector<int>,cmp> pq;
    pq.push(4);
    pq.push(2);
    pq.push(6);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
