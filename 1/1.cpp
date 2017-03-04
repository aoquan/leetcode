#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result(2);
		int countSize = nums.size();
		int i,j;
		bool tag=0;
		for (i=0;i<countSize;i++){
			for(j=i+1;j<countSize;j++){
				if(nums[i]+nums[j]==target){
					result[0]=i;
					result[1]=j;
					tag=1;
					break;				
				}

				if(tag==1){

				    break;
				}
			}
		}
        return result;
    }
};

int main(){
	Solution s;
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(11);
	arr.push_back(15);
	s.twoSum(arr,9);
}
