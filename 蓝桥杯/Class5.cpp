#include <iostream>

using namespace std;

int main(){
    int n, i, ans=12;
    // cin>>n;
    n=8;
    if(n==3){
        cout<<4;
        return 0;
    } else if(n==4){
        cout<<6;
        return 0;
    } else {
        n-=6;
    }
    for(i=0;i<n;i+=2){
        ans*=2;
    }
    cout<<ans;
    return 0;
}