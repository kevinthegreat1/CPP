#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}

int lcf(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<gcd(a,b)<<","<<lcf(a,b);
    return 0;
}