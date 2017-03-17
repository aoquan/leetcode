#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
        int *aux;
    public:
        Solution(){
            aux = new int[10];
        }
         void merge(int arr[],int l,int mid,int h){
            int i=l,j =mid+1;
            int k;
            for(k=l;k<=h;k++){
                aux[k]=arr[k];
            }
            for(k=l;k<=h;k++){
                if(i>mid){ //aux[l~mid] is sorted
                    arr[k] = aux[j++];
                    continue;
                }else if(j>h){  // aux[mid+1~h] is sorted
                    arr[k] = aux[i++];
                    continue;
                }
                if(aux[i]<aux[j]){
                    arr[k] = aux[i++];
                }else{
                    arr[k]=aux[j++];
                }
            }
            return;
        }

        void mergeSort(int arr[],int l,int h){
            if(l>=h) return;
            int mid = (l+h)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,h);
            merge(arr,l,mid,h);
        } 

};
int main(){
    int arr[]={1,4,2,5,7,3,1,3,5,0};
    Solution s;
    s.mergeSort(arr,0,9);
    for(int i=0;i<10;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
