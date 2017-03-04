#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)return NULL;
        if(!head->next) return head;
        if(!head->next->next){
            head->next->next = head;
            head = head->next;
            head->next->next = NULL;
            return head;
        }
        ListNode *p,*q,*r;
        for(p=head,q=p->next,r=q->next;r;){
            q->next = r->next;
            r->next = p->next;
            p->next = r;
            r = q->next ;
        }
        head = p->next;
        q->next=p;
        p->next=NULL;
        return head;
    }
};
void printList(ListNode * head){
    while(head){
        cout<<head->val<<" ";
        head =head ->next;
    }
    cout<<endl;
    return ;
}
int main(){
    int x;
    ListNode * head =new ListNode(0);
    ListNode * p;
    while(cin>>x){
        p = new ListNode(x);
        p->next = head;
        head= p;
    }
    p=head;
    printList(p);
    Solution S;
    p=head;
    p=S.swapPairs(head);
    printList(p);
    return 0;
}
