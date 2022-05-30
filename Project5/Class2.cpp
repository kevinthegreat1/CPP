#include <iostream>

using namespace std;

int main(){
    int n, i, j, fish=0, cost=0, cost1=0;
    cin>>n;
    int a[n][2];
    for(i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(i=0;i<n;i++){
        if(fish==0){
            cost+=a[i][0];
        } else {
            fish--;
        }
        cost1=0;
        cost1+=a[i][0];
        for(j=i;j<n;j++){
            cost1+=a[j][1];
            if(j<fish){
                continue;
            }
            if(cost1<a[j+1][0]){
                cost+=cost1;
                fish++;
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}