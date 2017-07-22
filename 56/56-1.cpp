#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
struct Node{
    int value;
    bool isStart;
    Node(int v, bool flag) : value(v), isStart(flag){}
    bool operator<(Node other){
        if(value == other.value) return isStart;
        return value < other.value;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Node> vnode;
        vector<Interval> vitl;
        vector<Interval>::iterator it;
        vector<Node>::iterator it1;
        stack<int> st;
        for(it = intervals.begin(); it != intervals.end(); it++){
            vnode.push_back(Node(it->start,true));
            vnode.push_back(Node(it->end,false));
        }
        sort(vnode.begin(),vnode.end());
        shownode(vnode);

        for(it1 = vnode.begin(); it1 != vnode.end(); it1++){
            if(it1->isStart){
                st.push(it1->value);
            }
            else{
                int tmpvalue = st.top();
                st.pop();
                if(st.empty()){
                    vitl.push_back(Interval(tmpvalue,it1->value));
                }
            }
        }
        return vitl;
    }

    void show(vector<Interval>& itls){
        int len = itls.size();
        int i;
        for(i = 0; i < len; i++){
            cout<< itls[i].start<<" "<<itls[i].end<<endl;
        }
    }

    void shownode(vector<Node> vnode){
        int i, len =  vnode.size();
        for(i = 0; i < len; i++){
            cout<<vnode[i].value<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    vector<Interval> itls,re;
    int m,n;
    while(cin>>m>>n){
        itls.push_back(Interval(m,n));
    }
    re = s.merge(itls);
    s.show(re);
}
