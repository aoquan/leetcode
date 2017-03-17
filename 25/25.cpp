#include<iostream>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode *next;
       //ListNode(){val(0),next}
        ListNode(int x){val=x,next=NULL;}
};
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head) return NULL;
            int j=0;
            ListNode* p=head,*re,*prev=NULL;
            while(p){
               ListNode *q=p,*r,*t=p;
               int i;
               for(i=0;i<k-1&&q->next;i++){
                    q=q->next;
               } 
               if(i!=k-1){
                   if(!prev) return p;
                   prev->next = p;
                   break;
               }
               r=q->next;
               q->next=NULL;
               ListNode * tmp = revert(t);
               if(j==0) re = tmp;
               if(prev)prev->next = tmp;
               prev = p;
               p=r;
               j++;
            }
            return re;
        }
        ListNode* revert(ListNode *pHead){
            ListNode *pPrev,*pNode;
            pNode = pHead;
            pPrev = NULL;
            while(pNode){
                ListNode *pNext = pNode->next;
                pNode->next = pPrev;
                pPrev = pNode;
                pNode = pNext;
            }
            return pPrev;
        }
};
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
    /*
    p=head;
    ListNode * q = revert(p);
    printList(q);
    */

    Solution s;
    p=head;
    ListNode * q= s.reverseKGroup(p,2);
    printList(q);
    return 0;
}
