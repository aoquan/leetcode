#include<iostream>
using namespace std;
void cal_next(string pattern,int *next,int len){
    next[0]=-1;
    int i,j;
    for(i=1;i<len;i++){
        j = next[i-1];
        while(pattern[j+1]!=pattern[i] && j>=0){
            j=next[j];
        }
        if(pattern[i]==pattern[j+1]){
            next[i]=j+1;
        }
        else{
            next[i]=-1;
        }
    }
}
int kmp(string target,string pattern,int * next){
    int target_len = target.length();
    int pattern_len = pattern.length();
    int target_index = 0,pattern_index = 0;

    while(target_index<target_len && pattern_index<pattern_len){
        if(target[target_index]==pattern[pattern_index]){
            target_index ++;
            pattern_index ++;
        }
        else{
            if(pattern_index==0){
                target_index ++;
            }
            else{
                pattern_index = next[pattern_index-1]+1;
            }
        }
    }
    return (pattern_index == pattern_len) ? (target_index - pattern_len) : -1;
}

int main(){
    string pattern;
    cin>>pattern;
    int len = pattern.length();
    int * next = new int[len];
    cal_next(pattern,next,len);
    int i;
    for(i=0;i<len;i++){
        cout<<next[i]<<ends;
    }
    cout<<endl;
    string target;
    cin >> target;
    cout<<kmp(target,pattern,next) <<endl;
    return 0;
}
