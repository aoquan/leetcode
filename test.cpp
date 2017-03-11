#include<iostream>
using namespace std;
struct A{
    private:
    int a;
    public:
    int func(int b){return b;}
};
int main(){
    A a;
    a.func(3);
    return 0;
}
