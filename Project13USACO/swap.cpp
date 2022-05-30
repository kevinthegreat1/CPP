#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    int n, k, a1, a2, b1, b2, rule, i, j;
    fin>>n>>k;
    fin>>a1>>a2;
    fin>>b1>>b2;
    int arr[n+1], arr1[n+1];
    for(i=1;i<=n;i++){
        arr[i]=i;
    }
    fin.close();
    copy(arr,arr+n+1,arr1);
    for (i=1;;i++){
        reverse(arr+a1,arr+a2+1);
        reverse(arr+b1,arr+b2+1);
        bool flag=false;
        for(j=1;j<=n;j++){
            if(arr[j]!=arr1[j]){
                flag=true;
            }
        }
        if(!flag){
            rule=i;
            break;
        }
    }
    k%=rule;
    for(i=0;i<k;i++){
        reverse(arr+a1,arr+a2+1);
        reverse(arr+b1,arr+b2+1);
    }
    for(i=1;i<=n;i++){
        fout<<arr[i]<<endl;
    }
    fout.close();
    return 0;
}