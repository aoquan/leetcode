#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int i,j;
            int len = nums.size();
            if(len==0) return 1;
            for(i=0;i<len;){
                if(nums[i]>=0 && nums[i]<len+1 && nums[i]-1 >=0 && nums[i]-1<len && nums[i]!=i+1 && nums[i]!=nums[nums[i]-1]){
                    swap(nums[i],nums[nums[i]-1]);
                }
                else{
                    i++;
                }
            }
            print_vector(nums);
            for(i=0;i<nums.size();i++){
                if(nums[i]!=i+1){
                    return i+1;
                }
            }
            return len +1;
        }

        void print_vector(vector<int>& nums){
            vector<int>::iterator it;
            for(it=nums.begin();it!=nums.end();it++){
                cout<<*it<<" ";
            }
            cout<<endl;
        
        }
};
int main(){
    vector<int> nums;
    nums.push_back(1);
    Solution s;
    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}
