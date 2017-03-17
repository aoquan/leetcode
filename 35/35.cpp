#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int size = nums.size();
            if(size==0) {
                return 0;
            }
            int pos = search(nums,0,size-1,target);
            return pos;
        }

        int search(vector<int>& nums,int l,int h,int target){
            if(l>h) return l;
            int mid = (l+h)/2;
            int s1,s2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                return search(nums,mid+1,h,target);
            }
            else{
                return search(nums,l,mid-1,target);
            }
        }
};


int main(){
    Solution s;
    vector<int> vct_int;
    int a;
    ifstream ifs("input.txt");
    while(ifs>>a){
        vct_int.push_back(a);
    }
    cout<<s.searchInsert(vct_int,0)<<endl;
    
}
