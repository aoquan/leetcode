#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk_char;
        stk_char.push(-1);
        int len = s.length();
        int i;
        int result=0;
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                stk_char.push(i);
            }
            else{
                stk_char.pop();
                if(stk_char.size()>0){
                    int tmp = i-stk_char.top();
                    result = max(result,tmp);
                }
                else{
                    stk_char.push(i);
                }
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.longestValidParentheses("()")<<endl;
    return 0;
}
