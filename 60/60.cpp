#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            string str = "", nums = "1234567890";
            int fac[10];
            int i, j, tmp;
            fac[0] = 1;
            for(i = 1; i <= n; i++){
                fac[i] = fac[i - 1] * i;
            }
            k--;
            for(i = 1; i <= n; i++){
                tmp = k / fac[n - i];
                str +=  nums[tmp];
                for(j = tmp; j < n; j++){
                    nums[j] = nums[j + 1];
                }
                k = k % fac[n - i];
            }
            return str;
        }
};
int main(){
    Solution s;
    int n,k;
    cin>>n>>k;
    cout<<s.getPermutation(n,k)<<endl;
}
