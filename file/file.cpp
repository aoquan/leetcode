#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream ifile("abc.txt");
    ofstream ofile("a.txt");
//    ifile.is_open();
    int a,b;
    string s;
    
    while(getline(ifile,s)){
        cout<<s<<endl;
        ofile<<s;
    }
    ifile.close();


}
