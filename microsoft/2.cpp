#include <iostream>
using namespace std;
long long job_hours(long long n,int q){
    long long robots=1;
    long long hours = 0;
    while(n>0){
        if(robots*q<n&&q+(n+robots*2-1)/(robots*2)<(n+robots-1)/robots){
            robots = robots*2;
            hours += q;
            //n -=robots;
        }
        else{
            hours ++;
            n -= robots;
        }
    }
    return hours;

}
int main(){
    long long n;
    int q;
    cin>>n>>q;
    cout<<job_hours(n,q)<<endl;
    return 0;
}
