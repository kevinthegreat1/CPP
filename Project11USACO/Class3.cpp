#include <iostream>
#include <algorithm>

using namespace std;

void my_next_permutation(int arr[],int len){
    int i=len-2, j=len-1, k;
    for(; i>=0 && arr[i]>=arr[j]; i--, j--){}
    if(i>=0){
        for(k=len-1;arr[i]>=arr[k];k--){}
        swap(arr[i],arr[k]);
    }
    for(i=len-1;i>j;j++,i--){
        swap(arr[i],arr[j]);
    }
    return;
}

int main(){
    int arr[5]={1,2,3,4,5};
    my_next_permutation(arr, 5);
    cout<<arr[0]<<", "<<arr[1]<<", "<<arr[2]<<", "<<arr[3]<<", "<<arr[4];
    return 0;
}