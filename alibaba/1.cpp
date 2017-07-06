#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
bool duicheng(string str,int l,int h){
    if(l>h) return false;
    if(l==h) return true;
    if(str[l]==str[h]){
        return duicheng(str,l+1,h-1);
    }
    else{
        return false;
    }
}

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int findMissedBuilding(string route) {
    string str=route;
    int len = route.length();
    int i,j;
    for(i=len-1;i>=0;i--){
        for(j=0;j<len;j++){
            if(i<=j) break;
            if(duicheng(route,j,i)){
                return j;
            }
        }
    }
    return len-1;

}

int main() {
    int res;

    string _route;
    getline(cin, _route);
    
    res = findMissedBuilding(_route);
    cout << res << endl;
    
    return 0;

}
