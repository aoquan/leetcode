#include <iostream>
using namespace std;
int fibRecursion(int a){
    if(a <= 0) return 0;
    if(a == 1 || a == 2) return 1;
    else return fibRecursion(a-1)+fibRecursion(a-2);
}
int fib(int a){
    if(a <= 0) return 0;
    if(a == 1 || a == 2) return 1;
    int fn_1,fn_2,fn;
    fn_2 = 1;
    fn_1 = 1;
    int i;
    for(i = 2; i < a; i++){
        fn = fn_2 + fn_1;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
}
int main(){
    int a;
    cin >> a;
//    cout<<fibRecursion(a)<<endl;
    cout<<fib(a)<<endl;
}
