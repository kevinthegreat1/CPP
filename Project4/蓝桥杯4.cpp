#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    bool a=false;
    int n, k, i, j;
    cin>>n>>k;
    int input[n+1], input1[n+1];
    int ans[100][n];
    for(i=0;i<n;i++){
        cin>>input[i];
    }
    for(i=0;(i+k)<n;i++){
        copy(input,input+n,input1);
        sort(input1,input1+k);
        for(j=0;ans[j][0]!=0 && ans[j][1]!=0 && ans[j][2]!=0 && equal(input1,input1+n,ans[j]);j++){
            a=true;
        }
        if(!a){
            copy(input1,input1+n,ans[j]);
        }
    }
    for(i=0,j=0;ans[i][0]!=0 && ans[j][1]!=0 && ans[j][2]!=0;i++){
        j++;
    }
    cout<<j;
    return 0;
}