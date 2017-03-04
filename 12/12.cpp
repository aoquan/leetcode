#include<iostream>
using namespace std;
class Solution{
    public:
        int arr[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string str[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string intToRoman(int num){
            string rom="";
            int i=12;
            while(num>0 && i>=0){
                if(num>=arr[i]){
                    num = num-arr[i];
                    rom+=str[i];
                    continue;
                }
                i--;
            }
            return rom;
        }
};
int main(){
    Solution s;
    int i;
    cin>>i;
    cout<<s.intToRoman(i)<<endl;
}
    
