#include<iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)return 0;
        if(x<0) return -rev(-x,0);
        else return rev(x,0);
    }
    int rev(long long x,long long y){
        if(x==0) return y;
        else{
            long long t = y*10+x%10;
            if(t<=INT_MAX ){
                return rev(x/10,y*10+x%10);
            }
            else{
                return 0;
            }
        }
    }
};
int main(){
    Solution s;
    int x;
    cin>>x;
    cout<<s.reverse(x)<<endl;
}
