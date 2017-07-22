#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
            vector<vector<int> > generateMatrix(int n) {
                vector<vector<int> > result;
                if(n == 0) return result;
                int i, count = 1;
                for(i = 0; i < n; i++){
                    result.push_back(vector<int>(n,0));
                }
                int c, cycle = (n + 1)/2;
                for(c = 0; c < cycle; c++){
                    for(i = c; i < n-c; i++){
                        result[c][i] = count++;
                    }   

                    for(i = c + 1; i < n - c; i ++){
                        result[i][n-c-1] = count++;
                    }   

                    for(i = n - c - 2; i >= c && n -c -1 != c; i--){
                        result[n - c -1][i] = count++;
                    }   

                    for(i = n -c -2; i >= c + 1 && n -c -1 != c; i--){
                        result[i][c] = count ++;
                    }   
                }
                return result;

            }
};

void show(vector<vector<int> >& vct){
    int len = vct.size();
    int i, j;
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            cout<< vct[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<vector<int> > result = s.generateMatrix(n);
    show(result);
}
