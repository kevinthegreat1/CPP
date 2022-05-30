#include <iostream>

using namespace std;

int main(){
    int n,i,j;
    // cin>>n;
    n=5;
    for(i=0;i<n;i++){
        cout<<"*";
    }
    cout<<endl;
    for(i=n-2;i>0;i--){
        for(j=i;j>0;j--){
            cout<<" ";
        }
        cout<<"*"<<endl;
    }
    for(i=0;i<n;i++){
        cout<<"*";
    }
    return 0;
}