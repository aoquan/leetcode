#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<int> vct;
    cin>>n;
    int total=0,total_tail=0;
    int i,j;
    for(i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        total += tmp/1024;
        vct.push_back(tmp/1024);
    }

    int **dp=new int*[n+1];
     for(int i=0;i<=n;i++){
      dp[i]=new int[total/2+1]();
     } 
     dp[0][0]=1;
     //递推求解
     for(int k=1;k<=n;k++){
        for(int i=k;i>=1;i--){
            for(int j=vct[k];j<=total/2;j++){
                if(dp[i-1][j-vct[k]])
                    dp[i][j]=1;
            }
        }
     }






    return 0;
}
