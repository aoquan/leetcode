#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
    private:
        static int cmp(const void *p1,const void *p2){
            return *(int*)p1 - *(int*)p2;
    }
    private:
        void show(const vector<int> &nums){
            for(int i=0;i<nums.size();i++)
                cout<<nums[i]<<" ";
            cout<<endl;
    }
    public:
        int threeSumClosest(vector<int>& nums,int target){
            int len = nums.size();
            int i,j,k;
            int sum = nums[0]+nums[1]+nums[2];
            int re = sum;
            int diff=abs(sum-target);
            int tmp;
            show(nums);
            qsort(&nums[0],len,sizeof(int),cmp);
            show(nums);
            for(i=0;i<len-2;i++){
                for(j=i+1,k=len-1;j<k;){
                    sum = nums[i]+nums[j]+nums[k];
                    if(abs(sum-target)<diff){
                        re=sum;
                        diff = abs(sum-target);
                    }
                    if(sum<target) j++;
                    else k--;
                }
            }
            return re;
        }
};
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
    v.push_back(16);
    v.push_back(32);
    v.push_back(64);
    v.push_back(128);
    Solution s;
    cout<<s.threeSumClosest(v,82)<<endl;
    return 0;
}
