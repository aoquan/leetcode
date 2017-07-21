#include <iostream>
using namespace std;
class Solution {
    private:
        int size;
        int * maxtix;
    public:
            vector<vector<string>> solveNQueens(int n) {
                size = n;
                maxtix = new int[n];
                vector<vector<string> > result;
                Search(result,n);
            }
            void Search(vector<vector<string> >& result, int n){
                int i,j;
                if(n >= size){
                    PutVct();
                    return;
                }
                for(i = 0; i < n ;i++){
                    c[n] = i;
                    for(j = 0; j < n ;j ++){
                        if(c[n] == c[j])
                    }
                }

            }

            void PutVct(){
            
            }
}
int main(){
}
