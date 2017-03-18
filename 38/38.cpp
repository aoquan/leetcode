#include<iostream>
using namespace std;
class Solution {
    public:
        string countAndSay(int n) {
            string start = "1";
            string str="";
            int i,j;
            for(i=0;i<n-1;i++){
                int pos = 0;
                for(j=0;j<start.length();j++){
                    if(start[j]!=start[pos]){
                        str.push_back(j-pos +'0');
                        str = str + start[pos];
                        pos = j;
                    }
                    if(j == start.length()-1){
                        str.push_back(j-pos+1 +'0');
                        str = str + start[pos];
                    }
                }
                start = str;
                str="";
            }
            return start;
        }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.countAndSay(n)<<endl;

}
