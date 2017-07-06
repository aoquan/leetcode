#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isSerial(vector<int> ins,vector<int> outs){
    stack<int> stk;
    int pos_in = 0;
    int pos_out = 0;
    stk.push(ins[pos_in++]);
    while(pos_out < outs.size()){
        while(stk.top() != outs[pos_out] && pos_in < ins.size()){
            stk.push(ins[pos_in++]);
        }
        if(stk.top() == outs[pos_out]){
            stk.pop();
            pos_out++;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> ins;
    vector<int> outs;
    ins.push_back(1);
    ins.push_back(2);
    ins.push_back(3);
    ins.push_back(4);
    ins.push_back(5);

    outs.push_back(4);
    outs.push_back(5);
    outs.push_back(3);
    outs.push_back(2);
    outs.push_back(1);

    cout<< isSerial(ins,outs)<<endl;
    return 0;
}
