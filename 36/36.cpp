#include<iostream>
#include<vector>
#include<fstream>
#include<set>
using namespace std;
class Solution {
    public:
        bool isValidSudoku(vector<vector<char> >& board) {
            int i,j;
            set<char> set_int;
            int length = board.size();
            int width = board[0].size(); 
            bool result;
            for(i=0;i<length;i++){
                set_int.clear();
                for(j=0;j<width;j++){
                    if(board[i][j]=='.') continue;
                    if(set_int.find(board[i][j])==set_int.end()){
                        set_int.insert(board[i][j]);
                    }
                    else{
                        return false;
                    }
                }
            }

            for(i=0;i<width;i++){
                set_int.clear();
                for(j=0;j<length;j++){
                    if(board[j][i]=='.') continue;
                    if(set_int.find(board[j][i])==set_int.end()){
                        set_int.insert(board[j][i]);
                    }
                    else{
                        return false;
                    }
                }
            }

            for(i=0;i<=length-3;i+=3){
                for(j=0;j<=width-3;j+=3){
                    set_int.clear();
                    int k,l;
                    for(k=i;k<i+3;k++){
                        for(l=j;l<j+3;l++){
                            if(board[k][l]=='.') continue;
                            if(set_int.find(board[k][l])==set_int.end()){
                                set_int.insert(board[k][l]);
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
};
int main(){
    ifstream ifs("input.txt");
    int i,j;
    char ch;
    vector<vector<char> > board;
    for(i=0;i<9;i++){
        vector<char> vct_tmp;
        for(j=0;j<9;j++){
            ifs>>ch;
            vct_tmp.push_back(ch);
        }
        board.push_back(vct_tmp);
    }
    
    Solution s;
    cout<<s.isValidSudoku(board)<<endl;
    ifs.close();
    return 0;
}
