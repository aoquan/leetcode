#include <iostream>
using namespace std;
class node{
    public:
        node * next;
        int val;
};

node * merge(node * head1,node * head2){
    if(!head1) return head2;
    if(!head2) return head1;

    node * head = NULL;
    if(head1->val < head2->val){
        head = head1;
        head->next = merge(head1->next,head2);
    }
    else{
        head = head2;
        head->next = merge(head1,head2->next);
    }
    return head;
}

int main(){
    node * head1;

}
