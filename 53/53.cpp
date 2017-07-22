#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int len = nums.size();
            int i, maxsum=INT_MIN, tmpsum=0;
            for(i = 0; i < len; i++){
                tmpsum += nums[i];
                maxsum = max(maxsum, tmpsum);
                if(tmpsum < 0){
                    tmpsum = 0;
                }
            }
            return maxsum;
        }
};
int main(){
    vector<int> nums;
    int n;
    Solution s;
    while(cin>>n){
        nums.push_back(n);
    }
    cout<<s.maxSubArray(nums)<<endl;
    return 0;
}
