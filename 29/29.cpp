#include<iostream>
#include<limits.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        int res = 0;
        bool isneg = ((dividend^divisor)<0)?true:false;
        long long dd = dividend;
        long long ds = divisor;
        if(dd<0) dd=-dd;
        if(ds<0) ds=-ds;
        int digit=0;
        while(ds<=(dd>>1)){
            ds<<=1;
            digit++;
        }
        while(digit>=0){
            if(dd>=ds){
                dd-=ds;
                res+= 1<<digit;
            }
            ds>>=1;
            digit--;
        }
        if(res<0){
            if(isneg) return INT_MIN;
            return INT_MAX;
        }
        return isneg?-res:res;

    }
};
int main(){
    int a,b;
    cin>>a>>b;
    Solution s;
    cout<<s.divide(a,b)<<endl;
    
    return 0;
}
