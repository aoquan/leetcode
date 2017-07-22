#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    private:
        string str;
        vector<string> vct;
    public:
        string getPermutation(int n, int k) {
            int i;
            str = "";
            for(i = 0; i < n; i++){
                str += '1' + i;
            }
            permutaion(0,n,k);
            sort(vct.begin(),vct.end());
            return vct[k-1];
        }

        void permutaion(int d,int n,int k){
            if(d >= n){
                vct.push_back(str);
                return ;
            }
            else{
                int i;
                for(i = d; i < n; i++){
                    swap(str[d],str[i]);
                    permutaion(d + 1, n, k);
                    swap(str[d],str[i]);
                }
            }
        }
};
int main(){
    Solution s;
    int n,k;
    cin>>n>>k;
    cout<<s.getPermutation(n,k)<<endl;
}
