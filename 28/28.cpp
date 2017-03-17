#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack=="" && needle=="") return 0;
        int i,j=0;
        for(i=0;haystack[i+j]!=0;i++){
            for(j=0;needle[j]!=0;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            if(needle[j]==0) return i;
        }
        if(haystack[i+j]==0) return -1;
    }
};
int main(){
    string str1,str2;
    cin>>str1>>str2;
    Solution S;
    cout<< S.strStr(str1,str2)<<endl;
    cout<< S.strStr("","")<<endl;
    return 0;
}
