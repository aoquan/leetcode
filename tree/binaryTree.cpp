#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
ifstream ifs("input.txt");
class node{
    public:
        node * l,*r;
        int val;
        node():val(0),l(NULL),r(NULL){}
        node(int a):val(a),l(NULL),r(NULL){}
};
class vnode{
    public:
        node * p;
        int visited;
        vnode(node * n):p(n),visited(0){}
};
class Tree{
    public:
        void create_tree(node *& root){
            int a;
            ifs >>a;
            if(a==0){
                root = NULL;
            }
            else{
                root = new node(a);
                create_tree(root->l);
                create_tree(root->r);
            }
        }

        void pre_order(node * root){
            if(root){
                cout<<root->val<<" ";
                pre_order(root->l);
                pre_order(root->r);
            }
        }
        void mid_order(node * root){
            if(root){
                mid_order(root->l);
                cout<<root->val<<" ";
                mid_order(root->r);
            }
        }
        void after_order(node * root){
            if(root){
                after_order(root->l);
                after_order(root->r);
                cout<<root->val<<" ";
            }
        }

        void pre_order1(node * root){
            stack<node *> s;
            if(root==NULL)return;
            while(!s.empty()||root){
                while(root){
                    cout<<root->val<<" ";
                    s.push(root);
                    root=root->l;
                }
                node *p = s.top();
                s.pop();
                root=p->r;
            }
        }

        void mid_order1(node * root){
            stack<node *> s;
            if(root==NULL)return;
            while(!s.empty()||root){
                while(root){
                    s.push(root);
                    root=root->l;
                }
                node *p = s.top();
                cout<<p->val<<" ";
                s.pop();
                root=p->r;
            }
        }

        void after_order1(node * root){
            if(root==NULL)return;
            stack<vnode *> s;
            node *p =root;
            while(p){
                vnode *vp = new vnode(p);
                s.push(vp);
                p=p->l;
            }
            
            while(!s.empty()){
                vnode *vp=s.top();
                if(!(vp->p->r)||vp->visited==1){
                    cout<<vp->p->val<<" ";
                    s.pop();
                }
                else{
                    vp->visited =1;
                    p = vp->p->r;
                    while(p){
                        vnode *vp = new vnode(p);
                        s.push(vp);
                        p=p->l;
                    }
                }
            }
        }
};

int main(){
    node *root;
    Tree tree;
    tree.create_tree(root);
    tree.pre_order(root);
    cout<<endl;
    tree.pre_order1(root);
    cout<<endl;
    tree.mid_order(root);
    cout<<endl;
    tree.mid_order1(root);
    cout<<endl;
    tree.after_order(root);
    cout<<endl;
    tree.after_order1(root);
    cout<<endl;
}
