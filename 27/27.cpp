#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j=0;
        vector<int>::iterator iter;
        for(iter=nums.begin();iter!=nums.end();){
            if(*iter!=val) iter = nums.erase(iter);
            else iter++;
        }
        return j;
    }
};
int main(){
    return 0;
}

