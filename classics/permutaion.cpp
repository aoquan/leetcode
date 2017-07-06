#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
void permutation(char* pstr,char * pbegin){
    assert(pstr && pbegin);
    if(*pbegin == '\0'){
        cout<<pstr<<endl;
    }else{
        char * tmp;
        for(tmp = pbegin; *tmp != '\0'; tmp++){
            swap(*tmp,*pbegin);
            permutation(pstr,pbegin + 1);
            swap(*tmp,*pbegin);
        }
    }
}
int main(){
    char str[] = "1234";
    permutation(str,str);
    return 0;
}
