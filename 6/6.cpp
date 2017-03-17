#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len==0 || len ==1 || numRows ==1 ) return s;
        string str;

        int circle = (numRows-1)*2;
        
        for(int i=0;i<numRows;i++){
            for(int j=i;j<len;j+=circle){
                str += s[j];
                if(i!=0 && i!=numRows-1 ){
                    int t = j+circle-2*i;
                    if(t<len){
                        str +=s[t];
                    }
                }
            
            }
        }     
        return str;
    }
};
int main(){
    Solution s;
    string str;
    int row;
    cin>>str>>row;
    cout<<s.convert(str,row)<<endl;
}
