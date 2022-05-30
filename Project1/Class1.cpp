#include <iostream>
using namespace std;

int main(){
    int a=1;
    int b=2;
    cout<<min(a,b)<<endl;
    cout<<max(a,b)<<endl;
    return 0;
}

int min(int a, int b){
    return a<b?a:b;
}

int max(int a, int b){
    return a>b?a:b;
}