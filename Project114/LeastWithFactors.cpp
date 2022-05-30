//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>

using namespace std;

int main(){
    int n, count, i, j;
    cin>>n;
    for(i=n;;i++){
        for(j=1,count=0;j<=i;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count>=n){
            cout<<i;
            return 0;
        }
    }
}