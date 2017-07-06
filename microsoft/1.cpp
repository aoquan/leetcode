#include <iostream>
#include <math.h>
using namespace std;
class node{
    public:
        node * l,*r;
        int val,prol,pror;
        node():val(0),prol(0),pror(0),l(NULL),r(NULL){}
        node(int a):val(a),l(NULL),r(NULL){}
};

int p,q,n;
double sumtmp=0;

class Tree{
    public:
        void create_tree(node *& root,int prol,int pror,int val){
            int a;
            if(val==n+1){
                root=NULL;
                return ;
            }
            else{
                root = new node();
                root->prol =prol;
                root->pror =pror;
                root->val = val;
                int tmpl = ceil((p*1.0/pow(2,val+1)));
                if(prol==100){
                    create_tree(root->l,tmpl,100-tmpl,val+1);
                    return ;
                }

                double tmpr = pror+q;
                if(tmpr > 100) tmpr = 100;
                create_tree(root->l,tmpl,100-tmpl,val+1);
                if(val<n)
                    create_tree(root->r,tmpr,100-tmpr,val);
            }
        }

        void mid_order(node * root,double sum,int len){
            if(root&&root->val!=2){
                //cout<<root->val<<" "<<root->prol<<" "<<root->pror<<endl;
                double sm=sum;
                int ln = len;
                mid_order(root->l,sum *= root->prol/100.0,++len);
                sum = sm;
                len =ln;
                mid_order(root->r,sum *=root->pror/100.0,++len);
            }
            else{
                sumtmp +=sum*len;
            }
        }
        
};
int main(){
    cin>>p>>q>>n;
    Tree te;
    node * root;
    te.create_tree(root,p,100-p,0);
    te.mid_order(root,1,0);
    cout<<sumtmp<<endl;
    return 0;
}
