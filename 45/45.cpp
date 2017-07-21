#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {
            int ret = 0;
            int curRch = 0;
            int maxRch = 0;
            int i;
            for(i=0;i<nums.size();i++){
                if(curRch < i){
                    ret ++ ;
                    curRch = maxRch;
                }
                maxRch = max(maxRch,nums[i]+i);
            }
            return ret;
        }
};
int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    Solution s;
    cout<<s.jump(nums)<<endl;
}
