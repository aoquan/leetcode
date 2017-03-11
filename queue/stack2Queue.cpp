#include<iostream>
#include<stack>
using namespace std;
class cmp{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};
class my_list{
    private:
        stack<int> s1,s2;
    public:
        void enter_list(int num){
            s1.push(num);
        }
        int leave_list(){
            int top;
            if(!list_empty()){
                cout<<"list is empty";
                return -1;
            }
            if(!s2.empty()){
                top =s2.top();
                s2.pop();
            }else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                top =s2.top();
                s2.pop();
            }
            return top;
        }
        bool list_empty(){
            if(s1.empty()&&s2.empty()){
                return false;
            }else
                return true;
        }
};
int main(){
    my_list ml;
    ml.enter_list(1);
    ml.enter_list(2);
    ml.enter_list(3);
    ml.enter_list(4);
    cout<<ml.leave_list()<<endl;
    cout<<ml.leave_list()<<endl;
    ml.enter_list(5);
    ml.enter_list(6);
    cout<<ml.leave_list()<<endl;
    cout<<ml.leave_list()<<endl;
    cout<<ml.leave_list()<<endl;
    cout<<ml.leave_list()<<endl;

}
