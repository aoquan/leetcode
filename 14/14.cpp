#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        string longestCommonPrefix(vector<string>& strs){
            int num = strs.size();
            if(num==0) 
            int minlen = strs[0].length();
            string minStr=strs[0];
            int i,j;
            for(i=0;i<num;i++){
                if(strs[i].length()<minlen){
                    minlen = strs[i].length();   
                    minStr=strs[i];
                }
            }
            for(i=0;i<minlen;i++){
                for(j=0;j<num;j++){
                    if(strs[j][i]!=minStr[i]) break;
                }
                if(j!=num) break;
            }
            return minStr.substr(0,j);
        }
};
int main(){
    vector<string> strs;
    /*
    strs.push_back("");
    strs.push_back("ab");
    strs.push_back("abxc");
    strs.push_back("abcde");
    */
    Solution s;
    cout<<s.longestCommonPrefix(strs)<<endl;
}
