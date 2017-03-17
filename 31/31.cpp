#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i,j,k=0;
        bool flag = true;
        for(i=len-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                k=i-1;
                flag = false;
                break;
            }
        }
        for(i=len-1;i>0;i--){
            if(nums[i]>nums[k]){
                swap(nums[i],nums[k]);
                break;
            }
        }
        if(!flag)i=k+1;
        else i=0;
        for(j=i;j<(i+len)/2;j++){
            swap(nums[j],nums[len+i-j-1]);
        }
    }
};
void print_vector(vector<int>& vct_int){
    int i;
    int len = vct_int.size();
    for(i=0;i<len;i++)
        cout<<vct_int[i]<<ends;
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> vct_int;
    vct_int.push_back(3);
    vct_int.push_back(2);
    vct_int.push_back(1);
    s.nextPermutation(vct_int);
    print_vector(vct_int);
    return 0;
}
