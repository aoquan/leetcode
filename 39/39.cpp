#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    private:
        vector<vector<int> >result;
        vector<int> candi;
        int sum(vector<int>& vct_int){
            int s = 0;
            vector<int>::iterator it;
            for(it=vct_int.begin();it!=vct_int.end();it++){
                s+=*it;
            }
            return s;
        }
        void backtrace(vector<int>& vct_int,int target, int l){
            if(l>=candi.size()){
                return ;
            }
            int sum_vct = sum(vct_int);
            if(sum_vct==target){
                result.push_back(vct_int);
                return ;
            }
            else{
                if(sum_vct>target){
                    return ;
                }
                else{
                    int i=0;
                    for(i=l;i<candi.size();i++){
                        vct_int.push_back(candi[i]);
                        backtrace(vct_int,target,i); 
                        vct_int.pop_back();
                    }
                }
            }
            return ;
        }
    public:
        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            candi = candidates;
            vector<int> tmp;
            backtrace(tmp,target,0);
            return result;
        }

};
void print_vector(vector<vector<int> >& vec){
    vector<int>::iterator it_int;
    vector<vector<int> >::iterator it_vct;
    for(it_vct=vec.begin();it_vct!=vec.end();it_vct++){
        for(it_int=it_vct->begin();it_int!=it_vct->end();it_int++){
            cout<<*it_int<<ends;
        }
        cout<<endl;
    }
}

int main(){
    Solution s;
    vector<int> vct_int;
    vector<vector<int> > re;
    vct_int.push_back(2);
    vct_int.push_back(3);
    vct_int.push_back(6);
    vct_int.push_back(7);
    re = s.combinationSum(vct_int,2);
    print_vector(re);
    return 0;
}
