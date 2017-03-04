#include<iostream>
#include<map>
using namespace std;
class Solution{
    public:
        int romanToInt(string s){
            map<char,int> mp;
            mp['I']=1,mp['V']=5,mp['X']=10,mp['L']=50,mp['C']=100,mp['D']=500,mp['M']=1000;
            int len = s.length();
            int re=0;
            for(int i=0;i<len;i++){
                if(mp[s[i]]<mp[s[i+1]]){
                    re = mp[s[i+1]]-mp[s[i]]+re;
                    i++;
                    continue;
                }
                re = mp[s[i]]+re;
            }
            return re;
        }
};
int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.romanToInt(str)<<endl;
}
    
