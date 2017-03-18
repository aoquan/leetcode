#include<iostream>
#include<vector>
#include<fstream>
#include<set>
using namespace std;
class Solution {
    public:
        bool solveSudoku(vector<vector<char> >& board) {
            int length = board.size();
            int width = board[0].size(); 
            if(length!=9 || width!=9) return false;
            return dfsSolveSudoku(board,0,0);
            
        }
        bool dfsSolveSudoku(vector<vector<char> >& board, int i,int j){
            if(i==board.size()) return true;
            if(j>=board[0].size()) return dfsSolveSudoku(board,i+1,0);
            int k;
            if(board[i][j]!='.'){
                return dfsSolveSudoku(board,i,j+1);
            }
            for(k=1;k<=9;k++){
                board[i][j]='0'+k;
                if(check(board,i,j)==true){
                    if(dfsSolveSudoku(board,i,j+1)) return true;
                }
                board[i][j]='.';
            }
            return false;
        }


        bool check(vector<vector<char> >& board,int i, int j){
            set<char> set_char;
            int m,n;
            int length = board.size();
            int width = board[0].size(); 
            for(m=0;m<length;m++){
                if(board[m][j]=='.') continue;
                if(set_char.find(board[m][j])!=set_char.end()){
                    return false;
                }
                set_char.insert(board[m][j]);
            }
            set_char.clear();
            for(m=0;m<width;m++){
                if(board[i][m]=='.') continue;
                if(set_char.find(board[i][m])!=set_char.end()){
                    return false;
                }
                set_char.insert(board[i][m]);
            }
            set_char.clear();
            for(m=i-i%3;m<(i-i%3)+3;m++){
                for(n=j-j%3;n<(j-j%3)+3;n++){
                    if(board[m][n]=='.') continue;
                    if(set_char.find(board[m][n])!=set_char.end()){
                        return false;
                    }
                    set_char.insert(board[m][n]);
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
    /*
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(s.check(board,i,j)==false) cout<<i<<j<<endl;
        }
    }
    */

    cout<<s.solveSudoku(board)<<endl;
    ifs.close();
    return 0;
}
