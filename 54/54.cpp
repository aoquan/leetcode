#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
            vector<int> spiralOrder(vector<vector<int> >& matrix) {
                vector<int> result;
                int n = matrix.size();
                if(n == 0) return result;
                int m = matrix[0].size();
                if(m ==0) return result;
                int i, j;
                int c, cycle = (min(m,n) + 1)/2;

                for(c = 0; c < cycle; c++){
                    for(i = c; i < m-c; i++){
                        result.push_back(matrix[c][i]);
                    }   

                    for(i = c + 1; i < n - c; i ++){
                        result.push_back(matrix[i][m-c-1]);
                    }   

                    for(i = m - c - 2; i >= c && n -c -1 != c; i--){
                        result.push_back(matrix[n - c -1][i]);
                    }   

                    for(i = n -c -2; i >= c + 1 && m -c -1 != c; i--){
                        result.push_back(matrix[i][c]);
                    }   
                }
                return result;
            }   
};

void show(vector<int>& vct){
    int len = vct.size();
    int i = 0;
    for(i = 0; i < len; i++){
        cout<< vct[i]<<" ";
    }
    cout<<endl;
}
int main(){
}
