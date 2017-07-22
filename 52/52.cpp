#include <iostream>
#include <vector>
using namespace std;
class Solution {
    private:
        int size;
        int * maxtix;
        int total;
    public:
            int totalNQueens(int n){
                size = n;
                total = 0;
                maxtix = new int[n];
                Search(0);
                return total;
            }
            void Search(int r){
                int i,j;
                bool isOk;
                if(r >= size){
                    total ++;
                    return;
                }
                for(i = 0; i < size ;i++){
                    maxtix[r] = i;
                    isOk = true;
                    for(j = 0; j < r ;j ++){
                        if(maxtix[r] == maxtix[j] || maxtix[r] - maxtix[j] == r - j || maxtix[r] -maxtix[j] == j -r){
                            isOk = false;
                            break;
                        }
                    }
                    if(isOk){
                        Search(r+1);
                    }
                }
            }

};
int main(){
    Solution s;
    int n;
    cin>> n;
    cout<<s.totalNQueens(n)<<endl;
    return 0;
}
