#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int main(){
    cout<<gcd(lcm(10,16),lcm(24,27));
}