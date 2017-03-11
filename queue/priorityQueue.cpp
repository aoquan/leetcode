#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class cmp{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};
int main(){
    priority_queue<int,vector<int>,cmp> q;
    q.push(1);
    q.push(9);
    q.push(2);
    q.push(3);
    
    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }
}
