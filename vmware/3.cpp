#include <iostream>
#include <vector>
using namespace std;
int a[1001];
int b[1001];

int maxtmp=0;
void addsum(const vector<char> & vct)
{
    int sum=0;
    int i=0;
    for (vector<char>::const_iterator it = vct.begin(); it != vct.end(); ++it,i++){
        if(*it=='('){
            sum += a[i];
        }
        else{
            sum +=b[i];
        }
    }
    if(sum>=maxtmp){
        maxtmp = sum;
    }
    return ;
}

int maxValue=0; 
void pailie(int vctNum, vector<char> & vct)
{
    int left (0), right(0);
    for (vector<char>::iterator it = vct.begin(); it != vct.end(); ++it)
    {
        if ('(' == *it) left ++;
        else right ++;
    }
    if (right > left) return;
    
    if (left == right && left + right == vctNum)
    {
        addsum(vct);
        return ;
    }
    
    if (left + right >= vctNum)
    {
        return ;
    }
    if (left == right)
    {
        vct.push_back('(');
        pailie(vctNum, vct);
        vct.pop_back();
    }
    else if (vctNum - left == right)
    {
        vct.push_back(')');
        pailie(vctNum, vct);
        vct.pop_back();
    }
    else
    {
        vct.push_back('(');
        pailie(vctNum, vct);
        vct.pop_back();
        
        vct.push_back(')');
        pailie(vctNum, vct);
        vct.pop_back();
    }
    return ;
}

int main()
{
    int n;
    cin>>n;
    int i;
    for(i=0;i<2*n;i++){
        cin>>a[i];
    }
    for(i=0;i<2*n;i++){
        cin>>b[i];
    }

    vector<char> vct;
    pailie(2*n, vct);
    cout<< maxtmp<<endl;
    return 0;
}
