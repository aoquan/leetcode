#include <iostream>
#include <math.h>
using namespace std;
class Solution {
    public:
        int minPathSum(vector<vector<int> >& grid){
            int m = grid.size();
            if(m==0) return 0;
            int n = grid[0].size();
            if(n==0) return 0;
            int dp[1001][1001];
            int i,j;
            int tmp=0;
            for(i=0;i<m;i++){
                tmp = tmp + grid[i][0];
                dp[i][0] = tmp;
            }
            tmp = 0;
            for(j=0;j<n;j++){
                tmp = tmp + grid[i][0];
                dp[0][j]= tmp;
            }
            for(i=1;i<m;i++){
                for(j=1;j<n;j++){
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
                }
            }
            return dp[m-1][n-1];
        }
};
