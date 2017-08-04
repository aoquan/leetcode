#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
            int m = obstacleGrid.size();
            if(m==0)return 0;
            int n = obstacleGrid[0].size();
            if(n==0)return 0;
            int dp[101][101]={0};
            int i,j;
            if(obstacleGrid[0][0]==0)dp[0][0]=1;
            for(i=1;i<m;i++)
                if(obstacleGrid[i][0]==0){
                    dp[i][0] = dp[i-1][0];
                }
            for(j=1;j<n;j++)
                if(obstacleGrid[0][j]==0)
                    dp[0][j]=dp[0][j-1];
            for(i=1;i<m;i++){
                for(j=1;j<n;j++){
                    dp[i][j] = dp[i-1][j] +dp[i][j-1];
                    if(obstacleGrid[i][j]==1) dp[i][j]=0;
                }
            }
            return dp[m-1][n-1];
        }
};
int main(){
    return 0;
}
