#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
/*
int comp(const void *p1,const void *p2){
    return *(int*)p1 - *(int*)p2;
}
*/
class Solution {
    private:
        static int comp(const void *p1,const void *p2){
            return *((int*)p2) < *((int*)p1)?1:-1;
        }
        
    private:
        void show(const vector<int>& nums){
            for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
        }
    public:
        vector<vector<int> > threeSum(vector<int>& nums) {
            qsort(&nums[0],nums.size(),sizeof(int),comp);
            vector<vector<int> > re;
            int i,j,k;
            int a,b,c;
            for(i=0;i<nums.size()-2;i++){
                if(i>0 && nums[i]==nums[i-1]) continue;
                a=nums[i];
                for(j=i+1,k=nums.size()-1;j<k;){
                    b=nums[j];
                    c=nums[k];
                    if(a+b+c==0){
                        vector<int> tmp;
                        tmp.push_back(a);
                        tmp.push_back(b);
                        tmp.push_back(c);
                        re.push_back(tmp);
                        break;
                    }
                    if(a+b+c<0) j++;
                    if(a+b+c>0) k--;
                }
            }
            return re;
    }
};
int main(){
    Solution s;
    vector<int> nums ;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    s.threeSum(nums);
}
