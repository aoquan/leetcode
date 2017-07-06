#include <iostream>
#include <vector>
using namespace std;
class node{
    public:
        node * l,*r;
        int val;
        node():val(0),l(NULL),r(NULL){}
        node(int a):val(a),l(NULL),r(NULL){}
};
node * constuctByPreAndMid(vector<int> pre,vector<int> mid){
    vector<int> left_pre,left_mid,right_pre,right_mid;
    int pos = 0;
    int length = mid.size();
    if(length == 0) return NULL;
    node * head = new node(pre[0]);
    int i;
    for(i = 0; i < length;i++){
        if(pre[0] == mid[i]){
            pos = i;
            break;
        }
    }
    
    for(i = 1; i < pos + 1; i++){
        left_pre.push_back(pre[i]);
        left_mid.push_back(mid[i-1]);
    }

    for(i = pos + 1; i < length; i++){
        right_pre.push_back(pre[i]);
        right_mid.push_back(mid[i]);
    }

    head->l = constuctByPreAndMid(left_pre,left_mid);
    head->r = constuctByPreAndMid(right_pre,right_mid);
    return head;
}

void pre_order(node * root){
    if(root){
        cout<<root->val<<" ";
        pre_order(root->l);
        pre_order(root->r);
    }
}
void mid_order(node * root){
    if(root){
        mid_order(root->l);
        cout<<root->val<<" ";
        mid_order(root->r);
    }
}
void after_order(node * root){
    if(root){
        after_order(root->l);
        after_order(root->r);
        cout<<root->val<<" ";
    }
}

int main(){
    vector<int> pre,mid;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(5);
    pre.push_back(3);

    mid.push_back(4);
    mid.push_back(2);
    mid.push_back(5);
    mid.push_back(1);
    mid.push_back(3);

    node * head = constuctByPreAndMid(pre,mid);
    pre_order(head);
    cout<<endl;
    mid_order(head);
    cout<<endl;
    after_order(head);
    cout<<endl;
    return 0;
}

