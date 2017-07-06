#include <iostream> 
#define SIZE 4
using namespace std;
void search(int a[][SIZE],int target){
    int row=0,collum=SIZE-1;
    while(row < SIZE && collum >= 0){
        if(a[row][collum] > target){
            collum--;
        }
        if(a[row][collum] < target){
            row ++;
        }
        if(a[row][collum] == target){
            cout<<row<<" "<<collum<<endl;
            break;
        }
    }
}
int main(){
    int a[SIZE][SIZE] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    int target;
    cin>>target;
    search(a,target);
    return 0;
}
