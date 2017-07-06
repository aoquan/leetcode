#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len==0) return 0;
        int i,j,l,r;
        int l_value,r_value;
        int total = 0;
        for(i=0;i<len-1;i++){
            if(height[i]>height[i+1]){
                break;
            }
        }
        l=i;
        for(i=len;i>0;i--){
            if(height[i]>height[i-1]){
                break;
            }
        }
        r=i;

        l_value = height[l];
        r_value = height[r];
        i=l;
        j=r;
        while(i<j){
            i++;
            j--;
            while(i<=j && height[i]<l_value){
                total += l_value - height[i];
                i++;
            }
            l_value = height[i];
            while(i<=j && height[j]<r_value){
                total += r_value - height[j];
                j--;
            }
            r_value = height[j];
        }
        cout<<total<<endl;
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