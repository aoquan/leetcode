#include <iostream>
using namespace std;
int fun0num(int n)
{
    int num = 0;
    
    while(n)
    {
        num += n / 5;
        n = n / 5;
    }
    
    return num;
}
int main(){
    int a;
    while(cin>>a){
        int i=1,count=0;
        while(1){
            int tmp = fun0num(i);
            if(tmp==a){
                cout<<i<<endl;
                break;
            }
            if(tmp>a){
                int j=i/5;;
                while(j<=i){
                    int tmp1 = fun0num(j);
                    if(tmp1==a){
                        cout<<j<<endl;
                        break;
                    }
                    if(tmp1>a){
                        cout<<-1<<endl;
                        break;
                    }
                    j+=5;
                }

               // cout<<-1<<endl;
                break;
            }
            i*=5;
        }
    }
    return 0;
}
