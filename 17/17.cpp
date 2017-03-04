#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
        string str[10];
    public:
        Solution(){
            str[0]="";
            str[1]="";
            str[2]="abc";
            str[3]="def";
            str[4]="ghi";
            str[5]="jkl";
            str[6]="mon";
            str[7]="pqrs";
            str[8]="tuv";
            str[9]="wxyz";
        }

    public:
        vector<string> letterCombinations(string digits){
            vector<string> ret;
            int len = digits.length();
            if(len==0) return ret;

            ret.push_back("");
            for(int i=0;i<len;i++){
                if(digits[i]=='1' || digits[i]=='0') continue;
                int size = ret.size();
                for(int j=0;j<size;j++){
                    string cur = ret[0];
                    ret.erase(ret.begin());
                    for(int k=0;k<str[digits[i]-'0'].length();k++){
                        ret.push_back(cur+str[digits[i]-'0'][k]);
                    }
                }
            }
            for(int t=0;t<ret.size();t++) cout<<ret[t]<<endl;
            return ret;

        }
};
int main(){
    string str;
    cin>>str;
    Solution s;
    s.letterCombinations(str);
    return 0;
}
