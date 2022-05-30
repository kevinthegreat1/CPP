//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>

using namespace std;

int main(){
    int n, total=0;
    cin>>n;
    int costs[n], carry[n], dp[n];
    for(int i=0;i<n;i++){
        cin>>costs[i]>>carry[i];
        if(i==0){
            dp[0]=costs[0];
            total+=costs[0];
            continue;
        }
        dp[i]=min(dp[i-1]+carry[i-1],costs[i]);
        total+=dp[i];
    }
    cout<<total;
    return 0;
}