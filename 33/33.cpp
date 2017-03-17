#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Solution{
    public:
        int search(vector<int>& nums, int target) {
            int size = nums.size();
            if(size==0) return -1;
            return search_2(nums,0,size-1,target);
        }
        int search_2(vector<int>& array,int l,int h,int key){
            if(l>h) return -1; 
            int mid = (l+h)/2;
            if(array[mid]==key) return mid;
            
            if(array[l]<=array[mid]){
                if(array[mid]>key&&array[l]<=key){
                    return search_2(array,l,mid-1,key);
                }
                else{
                    return search_2(array,mid+1,h,key);
                }
            }
            else{
                if(array[mid]<key && array[h]>=key){
                    return search_2(array,mid+1,h,key);
                }
                else{
                    return search_2(array,l,mid-1,key);
                }
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
    cout<<s.search(vct_int,1)<<endl;
    return 0;
}
