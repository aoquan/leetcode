#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if(s1==0){
            return (nums2[(s2-1)/2] + nums2[s2/2])/2;
        }
        if(s2==0){
            return (nums1[(s1-1)/2] + nums1[s1/2])/2;
        }
        if(s1==s2==1){
            return (nums1[0]+nums2[0])/2.0;
        }
        if(s1==1){
            int t=(s2-1)/2;
            if((s1+s2)%2==0){
                if(nums2[t-1]>=nums1[0]) {
                    return (nums2[t-1]+nums2[t])/2.0;
                }
                if(nums2[t+1]>=nums1[0] && nums2[t-1]<=nums1[0]) {
                    return (nums2[t]+nums1[0])/2.0;
                }
                if(nums2[t+1]<nums1[0]){
                    return (nums2[t]+nums2[t+1])/2.0;
                }
            }
            else{
                if(nums2[t]>nums1[0]){
                    return nums2[t];
                }
                if(nums2[t+1]<nums1[0]){
                    return nums2[t+1];
                }
                if(nums2[t+1]>=nums1[0] && nums2[t]<=nums1[0]){
                    return nums1[0];
                }
            }
        }

        ///////
        if(s2==1){
            int t=(s1-1)/2;
            if((s1+s2)%2==0){
                if(nums1[t-1]>=nums2[0]) {
                    return (nums1[t-1]+nums1[t])/2.0;
                }
                if(nums1[t+1]>=nums2[0] && nums1[t-1]<=nums2[0]) {
                    return (nums1[t]+nums2[0])/2.0;
                }
                if(nums1[t+1]<nums2[0]){
                    return (nums1[t]+nums1[t+1])/2.0;
                }
            }
            else{
                if(nums1[t]>nums2[0]){
                    return nums1[t];
                }
                if(nums1[t+1]<nums2[0]){
                    return nums1[t+1];
                }
                if(nums1[t+1]>=nums2[0] && nums1[t]<=nums2[0]){
                    return nums2[0];
                }
            }
        }




        if(s1>s2){
            return findMid(nums1,nums2,s1,s2,0,s1-1);  
        }
        else{
            return findMid(nums2,nums1,s2,s1,0,s2-1);  
        }
    }  
  
    double findMid(vector<int>& nums1, vector<int>& nums2 , int m,int n,int l,int r){ 
        int c = (m+n-1)/2;
        int p = (l+r)/2;
        if(l>r){
            return findMid(nums2,nums1,n,m,0,n-1); 
        }

        if(nums1[p] >= nums2[c-p-1] && nums1[p] <= nums2[c-p]){
            if((m+n)%2==1){
                return nums1[p];
            }
            else{
                if(p<m){
                    return (nums1[p]+nums1[p+1])/2.0;
                }
                else{
                    return (nums1[p]+nums2[0])/2.0;
                }
            }
        }
        if(nums1[p] <= nums2[c-p-1]){
            return findMid(nums1,nums2,m,n,p+1,r);
        }
        else{
            return findMid(nums1,nums2,m,n,l,p-1);
        }
    }   

};
int main(){
    Solution s;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    cout<<s.findMedianSortedArrays(v1,v2)<<endl;    
    
}
