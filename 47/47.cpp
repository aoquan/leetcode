#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
    private:
        int len;
    public:
        vector<vector<int> > permuteUnique(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            len = nums.size();
            set<vector<int> > result;
            
            exchange(result,nums,0);
            return vector<vector<int> >(result.begin(),result.end());
        }
        void exchange(set<vector<int> >&result, vector<int>& nums, int m){
            if(m>=len){
                result.insert(nums);
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
    result = s.permuteUnique(nums);
    show(result);
    return 0;
}
