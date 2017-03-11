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
        void show(node *head){
            while(head){
                cout<<head->val<<" ";
                head=head->next;
            }
            cout<<endl;
        }

        node * create_list(){
            node *head=NULL,*p;
            int x;
            ifstream ifs("input.txt");
            while(ifs>>x){
                if(head==NULL){
                    head = new node(x);
                    continue;
                }
                p= new node(x);
                p->next = head;
                head = p;
            }
            ifs.close();
            return head;
        }

        void delete_node(node *&head,int num){
            node *p,*q;
            for(p=head;p->next&&p->val<num;q=p,p=p->next){
                ;
            }
            if(p==head){
                head = head->next;
                delete p;
            }
            if(p->next!=NULL){
                q->next=p->next;
                delete p;
            }
            return ;
        }

        void insert_node_before_head(node *&head,int num){
            node *p = new node(num);
            p->next = head;
            head = p;
        }

        void insert_node_after_tail(node *&head,int num){
            if(head==NULL){
                head = new node(num);
            }
            node *p = new node(num);
            node *q = head;
            while(q->next){
                q= q->next;
            }
            q->next = p;
        }

        void insert_node_after_num(node *&head,int num){
            if(head==NULL){
                head = new node(num);
                return ;
            }
            node *p,*q,*r;
            for(p=head;p->next&&p->val<num;q=p,p=p->next){
                ;
            }
            if(p->next!=NULL){
                r=new node(num);
                r->next =q->next;
                q->next = r;
            }else{
                r=new node(num);
                p->next = r;
            }
            return ;
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

        node * reverse_list(node *head){
            if(head==NULL|| head->next==NULL){
                return head;
            }
            node *new_head = reverse_list(head->next);
            head->next->next = head;
            head->next=NULL;
            return new_head;
        }
};
int main(){
    Solution s;
    node * head = s.create_list();
//    s.show(head);
//    s.delete_node(head,5);
//    s.show(head);
//   s.insert_node_before_head(head,5);
//   s.show(head);
//   s.insert_node_after_tail(head,10);
//   s.show(head);
//   s.insert_node_after_num(head,3);
//   s.show(head);

    s.sort_list(head);
    s.show(head);
    
    head = s.reverse_list(head);
    s.show(head);
}
