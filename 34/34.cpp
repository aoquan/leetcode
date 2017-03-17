#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Solution {
    private:
        vector<int> result;
        int size;
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            size = nums.size();
            if(size==0) {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
            int mid = search(nums,0,size-1,target);
            if(mid==-1){
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
           int i;
           for(i=mid;i>=0;i--){
               if(nums[i]!=target){
                   break;
               }
           }
           result.push_back(i+1);
           for(i=mid;i<size;i++){
               if(nums[i]!=target){
                   break;
               }
           }
           result.push_back(i-1);
            return result;
        }

        int search(vector<int>& nums,int l,int h,int target){
            if(l>h) return -1;
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
    vector<int> result = s.searchRange(vct_int,8);
    vector<int>::iterator it=result.begin();
    while(it!=result.end()){
        cout<<*it<<ends;
        it++;
    }
    cout<<endl;
    
}
