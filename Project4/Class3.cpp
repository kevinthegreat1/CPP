#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(a<b){
        swap(a,b);
    }
    int t;
    while(b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int gcd2(int a, int b){
    return b==0?a:gcd2(b,a%b);
}

int main(){
    cout<<gcd(34,58)<<endl;
    cout<<gcd2(34,58)<<endl;
    return 0;
}