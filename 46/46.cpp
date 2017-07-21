#include <iostream>
#include <vector>
using namespace std;
class Solution {
    private:
        int len;
    public:
        vector<vector<int> > permute(vector<int>& nums) {
            len = nums.size();
            vector<vector<int> > result;
            exchange(result,nums,0);
            return result;
        }
        void exchange(vector<vector<int> >&result, vector<int>& nums, int m){
            if(m>=len){
                result.push_back(nums);
                return ;
            }
            int i;
            for(i = m; i < len; i++){
                swap(nums[i],nums[m]);
                exchange(result,nums,m+1);
                swap(nums[i],nums[m]);
            }
        }
};

void show(vector<vector<int> >&nums){
    vector<vector<int> >::iterator it1;
    vector<int>::iterator it2;
    for(it1 = nums.begin(); it1 != nums.end(); it1++){
        for(it2 = (*it1).begin(); it2 != (*it1).end(); it2++){
            cout<<*it2<<" "; 
        }
        cout<<endl;
    }
}

int main(){
    vector<int> nums;
    vector<vector<int> > result;
    int n;
    Solution s;
    while(cin>>n){
        nums.push_back(n);
    }
    result = s.permute(nums);
    show(result);
    return 0;
}
