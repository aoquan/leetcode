#include <iostream>
using namespace std;
void caculate(string str){
    int *a[10];
    int b1[]={1,0,0,1,0,0,1,0,0,1,0,0,1,0,0};
    a[1] = b1;
    int b2[]={1,1,1,0,0,1,1,1,1,1,0,0,1,1,1};
    a[2]=b2;
    int b3[]={1,1,1,0,0,1,1,1,1,0,0,1,1,1,1};
    a[3]=b3;
    int b4[]={1,0,1,1,0,1,1,1,1,0,0,1,0,0,1};
    a[4]=b4;
    int b5[]={1,1,1,1,0,0,1,1,1,0,0,1,1,1,1};
    a[5]=b5;
    int b6[]={1,1,1,1,0,0,1,1,1,1,0,1,1,1,1};
    a[6]=b6;
    int b7[]={1,1,1,0,0,1,0,0,1,0,0,1,0,0,1};
    a[7]=b7;
    int b8[]={1,1,1,1,0,1,1,1,1,1,0,1,1,1,1};
    a[8]=b8;
    int b9[]={1,1,1,1,0,1,1,1,1,0,0,1,1,1,1};
    a[9]=b9;
    int b0[]={1,1,1,1,0,1,1,0,1,1,0,1,1,1,1};
    a[0]=b0;

    int ad[] =  {0,0,0,0,1,0,1,1,1,0,1,0,0,0,0};
    int minus[]={0,0,0,0,0,0,1,1,1,0,0,0,0,0,0};
    int multi[]={0,0,0,1,0,1,0,1,0,1,0,1,0,0,0};
    int div[] = {0,0,0,0,0,1,0,1,0,1,0,0,0,0,0};
    int  eq[] = {0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};
    int dot[] = {0,0,0,0,0,0,1,1,1,1};

    int len = str.length();
    int i,j,k,l;
    for(i=0;i<5;i++){
        for(j=0;j<len;j++){
            if(str[j]=='1'){
                cout<<"*  ";
            }
            if(str[j]<='9'&&str[j]>='0'&& str[j]!='1'){
                for(l=0;l<3;l++){
                    if(a[str[j]-'0'][l+i*3]==1) cout<<"*";
                    else cout<<" ";
                }
                if(j!=len-1)
                cout<<"  ";
            }
            else{
                if(str[j]=='+'){
                    for(k=0;k<3;k++){
                        if(ad[k+i*3]==1) cout<<"*";
                        else cout<<" ";
                    }
                if(j!=len-1)
                    cout<<"  ";
                }
                if(str[j]=='-'){
                    for(k=0;k<3;k++){
                        if(minus[k+i*3]==1) cout<<"*";
                        else cout<<" ";
                    }
                if(j!=len-1)
                    cout<<"  ";
                }
                if(str[j]=='*'){
                    for(k=0;k<3;k++){
                        if(multi[k+i*3]==1) cout<<"*";
                        else cout<<" ";
                    }
                if(j!=len-1)
                    cout<<"  ";
                }
                if(str[j]=='/'){
                    for(k=0;k<3;k++){
                        if(div[k+i*3]==1) cout<<"*";
                        else cout<<" ";
                    }
                if(j!=len-1)
                    cout<<"  ";
                }


                    if(str[j]=='='){
                        for(k=0;k<4;k++){
                            if(eq[k+i*4]==1) cout<<"*";
                            else cout<<" ";
                        }
                if(j!=len-1)
                        cout<<"  ";
                    }

                    if(str[j]=='.'){
                        for(k=0;k<2;k++){
                            if(dot[k+i*2]==1) cout<<"*";
                            else cout<<" ";
                        }
                if(j!=len-1)
                        cout<<"  ";
                    }
                }
        }
        cout<<endl;
    }
    
}
int main(){
    string str="",tmp;
    while(cin>>a){

        str+=tmp;
    }
    
    caculate(str);
    return 0;
}
