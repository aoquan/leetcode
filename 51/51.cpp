#include <iostream>
#include <vector>
using namespace std;
class Solution {
    private:
        int size;
        int * maxtix;
    public:
            vector<vector<string> >solveNQueens(int n) {
                size = n;
                maxtix = new int[n];
                vector<vector<string> > result;
                Search(result,0);
                return result;
            }
            void Search(vector<vector<string> >& result, int r){
                int i,j;
                bool isOk;
                if(r >= size){
                    PutVct(result);
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
                        Search(result,r+1);
                    }
                }
            }

            void PutVct(vector<vector<string> >& result){
                int i;
                vector<string> vct;
                string tmp;
                for(i = 0; i < size; i++){
                    tmp = string(size,'.');
                    tmp[maxtix[i]] = 'Q';
                    //cout<<tmp<<endl;
                    vct.push_back(tmp);
                }
                result.push_back(vct);
                //cout<<endl;
            }
};
int main(){
    Solution s;
    int n;
    cin>> n;
    s.solveNQueens(n);
    return 0;
}
