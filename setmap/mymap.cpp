#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int,string> mp;
    mp.insert(make_pair(1,"abc"));
    pair<int,string> pr(2,"vbn");
    mp.insert(pr);
    cout<<(mp.find(2))->second<<endl;
}
