#include<iostream>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode *next;
       //ListNode(){val(0),next}
        ListNode(int x){val=x,next=NULL;}
};
ListNode* revert(ListNode *p,ListNode *l){
    if(l->next){
        ListNode *q = l->next;
        ListNode *re = revert(l,q);
        l->next = p; 
        p->next = NULL;
        return re;
    }
    l->next = p;
    p->next=NULL;
    return l;
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
    ListNode * q = revert(p,p->next);
    printList(q);
    return 0;
}
