#include<iostream>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode *next;
       //ListNode(){val(0),next}
        ListNode(int x){val=x,next=NULL;}
};
ListNode* revert(ListNode *root){
    if(root->next){
        ListNode * p = root->next;
        root->next=NULL;
        ListNode *head = revert(p);
        p->next = root;
        return head;
    }
    return root;
}
void printList(ListNode *l){
    while(l){
        cout<<l->val<<" ";
        l=l->next;
    }
    cout<<endl;
}

int main(){
    int x;
    ListNode *p,*head;
    head = new ListNode(0);
    while(cin>>x){
        p = new ListNode(x);
        p->next = head;
        head = p;
    }
    p=head;
    printList(p);
    p=head;
    ListNode * q = revert(p);
    printList(q);
    return 0;
}
