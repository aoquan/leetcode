#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0;
        int j=len-1;
        int maxar=(j-i)*min(height[i],height[j]);
        while(i!=j){
            if(height[i]<height[j]) i++;
            else j--;
            int tmp = (j-i)*min(height[i],height[j]);
            if(maxar<tmp) maxar=tmp;
        }
        return maxar;
    }
};
int main(){
    Solution so;
    vector<int> he;
    he.push_back(1);
    he.push_back(2);
    cout<<so.maxArea(he)<<endl;
}
