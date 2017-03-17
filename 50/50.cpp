#include<iostream>
#include<limits.h>
using namespace std;
class Solution{
    public:
        double myPow(double x, int n){
            if(n==0)return 1;
            if(n<0) {
                if(n==INT_MIN) return 1.0/(myPow(x,INT_MAX)*x);
                else return 1.0/myPow(x,-n);
            }
            double ans=1;
            for(;n>0;x*=x,n>>=1){
                if(n&1>0){
                    ans *=x;
                }
            }
            return ans;
        }
};
int main(){
    double a;
    int n;
    Solution s;
    cin >>a>>n;
    cout<<s.myPow(a,n)<<endl;
}
