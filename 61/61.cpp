#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * revert(ListNode *root){
    if(root->next){
        ListNode * p = root->next;
        root->next=NULL;
        ListNode *re = revert(p);
        p->next = root;
        return re;
    }
    return root;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ) return head;
        int i,len;
        ListNode *p = head,*head1=head,*head2;
        ListNode * re;
        len=0;
        while(p){
            len++;
            p = p->next;
        }
        k=k%len;
        if(k == 0) return head;
        p=head;
        for(i=0;i<len-k-1;i++){
            p=p->next;
        }

        head2 = p->next;
        p->next = NULL;
        
        head1 = revert(head1);
        head2 = revert(head2);
        
        head->next = head2;
        re = revert(head1);
        return re;
    }
};
void show(ListNode * head){
    ListNode *p = head;
    while(p){
        cout<<p->val<<" ";
        p =p->next;
    }
    cout<<endl;
}

int main(){
    int k;
    cin>>k;
    ListNode * head = new ListNode(1);
    ListNode * tmp = new ListNode(2);
    head->next = tmp;
    tmp = new ListNode(3);
    head->next->next = tmp;
    tmp = new ListNode(4);
    head->next->next->next = tmp;
    tmp = new ListNode(5);
    head->next->next->next->next = tmp;
    show(head);
    Solution s;
    ListNode * re = s.rotateRight(head,k);
    show(re);

    return 0;
}
