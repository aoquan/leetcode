#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        bool canJump(vector<int>& nums) {
            int len = nums.size();
            if(len == 1)return true;
            int i, curmax = 0;
            for(i = 0; i < len - 1; i++){
                curmax = max(curmax, nums[i] + i);
                if(curmax >= len -1){
                    return true;
                }
                if(curmax == i) return false;
            }
            return false;
        }
};
int main(){
    vector<int> vct;
    int n;
    Solution s;
    while(cin>> n){
        vct.push_back(n);
    }
    cout<<s.canJump(vct)<<endl;


}
