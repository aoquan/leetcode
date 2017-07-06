#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int l= 0,r = height.size()-1;
        int total = 0;
        int lmax=height[l],rmax=height[r];
        while(l<=r){
            if(height[l]<height[r]){
                if(height[l]>lmax) lmax =  height[l];
                else total += lmax -height[l];
                l++;
            }
            else{
                if(height[r]>rmax) rmax = height[r];
                else total += rmax -height[r];
                r--;
            }
        }
        return total;
    }
};
void input_vector(vector<int> &v){
    int a;
    cin>>a;
    while(a>=0){
        v.push_back(a);
        cin>>a;
    }
    return ;
}
int main(){
    Solution  s;
    vector<int> height;
    input_vector(height);
    cout<<s.trap(height)<<endl;
    return 0;
}
