//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>

using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    for(int i=2;i<n;){
        if(n%i==0){
            count++;
            n/=i;
        } else {
            i++;
        }
    }
    cout<<count+1;
    return 0;
}