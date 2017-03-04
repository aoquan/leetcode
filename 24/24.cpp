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
        ListNode *p,*q,*r;
        p=head;
        q=p->next;
        head = q;
        r = q;
        int i=0;
        while(1){
            p->next = q->next;
            q->next = p;
            if(i!=0)r->next = q;
            r = p;           
            p=p->next;
            if(!p)return head;
            q=p->next;
            if(!q) return head;
            i++;
        }
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
