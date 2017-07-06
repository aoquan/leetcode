#include<iostream>
using namespace std;
int main(){
    char cal;
    string exp;
    int result,para1;
    cin>>exp;
    int len = exp.length();
    int i;
    if(exp[0]=='-') result = -(exp[1]-'0');
    else result = exp[0]-'0';
    for(i=1;i<len;i++){
        if(exp[i]<='9' && exp[i]>='0'){
            para1 = exp[i]-'0';
            if(cal=='+'){
                result = result+para1;
            }
            if(cal=='-'){
                result = result -para1;
            }
            if(cal=='*'){
                result = result*para1;
            }
        }
        else{
            cal=exp[i];
        }
    }
    cout<<result;
    return 0;
}
