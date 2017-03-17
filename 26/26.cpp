#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();

    }
};
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    Solution s;
    cout<<s.removeDuplicates(a)<<endl;
}
