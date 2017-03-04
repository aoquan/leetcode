#include<iostream>
using namespace std;
class Solution{
    public:
        bool isUgly(int num){
            if(num<1) return false;
            if(num==1) return true;
            while(num%2==0){
                num/=2;
            }
            while(num%3==0){
                num/=3;
            }
            while(num%5==0){
                num/=5;
            }
            if(num==1)return true;
            else return false;
        }
};
int main(){
    Solution s;
    int a;
    cin>>a;
    if(s.isUgly(a)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
