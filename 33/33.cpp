#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Solution{
    public:
        int search(vector<int>& nums, int target) {
            if(nums.size()==0) return -1;
            search_2(nums,0,nums.size()-1,target);
        }
        int search_2(vector<int>& array,int l,int h,int key){
            if(l>h) return -1; 
            int mid = (l+h)/2;
            if(array[mid]==key) return mid;
            
            if(array[mid]>key){
                if(array[l]>key){
                    return search_2(array,mid+1,h,key);
                }
                else{
                    return search_2(array,l,mid-1,key);
                }
            }
            if(array[mid]<key){
                if(array[h]<key){
                    return search_2(array,l,mid-1,key);
                }
                else{
                    return search_2(array,mid+1,h,key);
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
    cout<<s.search(vct_int,5)<<endl;
    return 0;
}
