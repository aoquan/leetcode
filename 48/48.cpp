#include <iostream>
using namespace std;
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            vector<vector<int> >tmp(matrix);
            int row, column;
            int i,j;
            vector<int> vct;
            row = matrix.size();
            column = matrix[0].size();
            matrix.erase(matrix.begin(),matrix.end());

            for(i = 0; i < column; i ++){
                for(j = row -1 ; j >= 0; j--){
                    vct.push_back(tmp[j][i]);
                }
                matrix.push_back(vct);
                vct.erase(vct.begin(),vct.end());
            }
        }
};

void show(vector<vector<int> >&nums){
    vector<vector<int> >::iterator it1;
    vector<int>::iterator it2;
    for(it1 = nums.begin(); it1 != nums.end(); it1++){
        for(it2 = (*it1).begin(); it2 != (*it1).end(); it2++){
            cout<<*it2<<" "; 
        }
        cout<<endl;
    }
}
int main(){

}
