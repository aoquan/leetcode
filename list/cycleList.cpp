#include<iostream>
#include<fstream>
using namespace std;
struct node{
    int val;
    node *next;
    node(int x):val(x),next(NULL){}
};
class Solution{
    public:
        void show(node *tail){
            node *p =tail->next;
            while(p!=tail){
                cout<<p->val<<" ";
                p=p->next;
            }
            cout<<p->val<<endl; 
        }

        node * create_list(){
            node * tail = new node(0);
            tail->next = tail;
            return tail;
        }

        void delete_node(node *&tail,int num){
            node *p,*q;
            for(p=tail->next;p!=tail&&p->val!=num;q=p,p=p->next){
                ;
            }
            if(p!=tail){
                q->next  = p->next;
                delete p;
            }else{
                if(p->val==num){
                    q->next = p->next;
                    delete p;
                    tail = q;
                }
            }
        }

        void insert_node_after_tail(node *&tail,int num){
            node * p = new node(num);
            p->next = tail->next;
            tail->next = p;
            tail = p;
        }

        void sort_list(node *&head){
            node *p,*q;
            for(p=head;p->next;p=p->next){
                for(q=head;q->next;q=q->next){
                    if(q->val<q->next->val){
                        swap(q->val,q->next->val);
                    }
                }
            }
        }

        void reverse_list(node *tail,node *head){
            if(head==tail){
                return ;
            }
            reverse_list(tail,head->next);
            head->next->next = head;
            head->next=tail;
            tail = head;
            return ;
        }

};
int main(){
    Solution s;
    node * tail = s.create_list();
    ifstream ifs("input.txt");
    int num;
    while(ifs>>num){
        s.insert_node_after_tail(tail,num);
    }
    s.show(tail);
    //s.insert_node_after_tail(tail,0);
    //s.show(tail);
    node * head = tail->next;
    s.reverse_list(tail,head);
    tail = head;
    s.show(tail);
}
