#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
    public:
            vector<vector<string> > groupAnagrams(vector<string>& strs) {
                map<string,vector<string> > mp;
                map<string,vector<string> >::iterator mp_it;
                string tmp;
                vector<vector<string> > result;
                vector<string>::iterator it;
                for(it = strs.begin(); it != strs.end(); it++){
                    tmp = GetOrder(*it);
                    mp[tmp].push_back(*it);
                }

                for(mp_it = mp.begin(); mp_it != mp.end();mp_it ++){
                    result.push_back(mp_it->second);
                }
                return result;
            }

            string GetOrder(string str){
                sort(str.begin(),str.end());
                return str;
            }
};
int main(){
    Solution s;
    string str = s.GetOrder("cab");
    cout<<str<<endl;
}
