#include<iostream>
#include<fstream>
using namespace std;
struct node{
    int val;
    node *next,*prev;
    node(int x):val(x),next(NULL),prev(NULL){}
};
class Solution{
    private:
        node * head;
        node * tail;
    public:
        Solution():head(NULL),tail(NULL){}
        void show(){
            node *p = head;
            while(p){
                cout<<p->val<<" ";
                p=p->next;
            }
            cout<<endl;
        }

        void create_list(){
            head = new node(0);
            tail = head;
        }

        void delete_node(int num){
            node *p;
            for(p=head;p->next&&p->val!=num;p=p->next){
                ;
            }
            if(p==head){
                head = head->next;
                head->prev = NULL;
                delete p;
                return ;
            }
            if(p->next!=NULL){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
            }else{
                p->prev->next = NULL;
                tail = p->prev;
                delete p;
            }
            return ;
        }

        void insert_node_before_head(int num){
            node *p = new node(num);
            head ->prev = p;
            p->next = head;
            head = p;
        }

        void insert_node_after_tail(int num){
            node *p = new node(num);
            tail->next = p;
            p->prev = tail;
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

};
int main(){
    Solution s;
    s.create_list();
    ifstream ifs("input.txt");
    int num;
    while(ifs>>num){
        s.insert_node_before_head(num);
        //s.insert_node_after_tail(num);
    }
    s.show();
    /*
    s.delete_node(3);
    s.show();
    */
//    s.reverse_list();
    s.show();

}
