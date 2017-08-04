#include <iostream>
#include <math.h>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if(m<n)swap(m,n);
            m--;
            n--;
            m = m+n;
            double result=1;
            while(n>0){
                result *= m*1.0/n;
                m--,n--;
            }
            return round(result);
        }
};
int main(){
    int m,n;
    Solution s;
    cin>>m>>n;
    cout<<s.uniquePaths(m,n);
    return 0;
}
