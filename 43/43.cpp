#include <iostream>
using namespace std;
class Solution {
    public:
        string multiply(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
            string re(len1+len2,'0');

            int mul=0,carry=0;
            int i,j,ten=1;
            for(j=len2-1;j>=0;j--){
                carry = 0;
                for(i=len1-1;i>=0;i--){
                    mul = re[i+j+1]-'0' + carry + (num1[i]-'0')*(num2[j]-'0');
                    carry = mul/10;
                    mul = mul%10;
                    re[i+j+1] = mul+'0';
                }
                re[j] += carry;
            }
            return re;
        }

};
int main(){
    Solution s;
    string num1,num2;
    cin>>num1>>num2;
    cout<<s.multiply(num1,num2)<<endl;
    return 0;
}
