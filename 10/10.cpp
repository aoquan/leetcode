#include<iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size()==0){
            if(s.size()==0) return true;
            else return false;
        } 
        if(p.size()==1 && s.size()==1){
            if(p[0]==s[0] || p[0]=='.') return true;
            else return false;
        }
        if(p[1]!='*'){
            if(s.empty()) return false;
            else return ((p[0]==s[0] || p[0]=='.') && isMatch(s.substr(1),p.substr(1)));
        }

        while(!s.empty()&& (s[0]==p[0]||p[0]=='.')){
            if(isMatch(s,p.substr(2))) return true;
            s=s.substr(1);
        }
        return isMatch(s,p.substr(2));
    }
};
int main(){
    Solution so;
    string s;
    string p;
    cin >>s>>p;
    if(so.isMatch(s,p)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}
