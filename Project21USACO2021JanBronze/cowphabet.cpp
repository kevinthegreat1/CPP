//
// Created by Kevin Yang on 2/11/21.
//

#include <iostream>

using namespace std;

int main(){
    int i, j, k;
    string cowphabet, heard;
    cin>>cowphabet>>heard;
    for(i=1,k=0;;i++){
        for(j=0;j<26;j++){
            if(heard[k]==cowphabet[j]){
                k++;
            }
        }
        if(k==heard.size()){
            cout<<i;
            return 0;
        }
    }
}