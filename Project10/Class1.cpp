#include <iostream>

using namespace std;

int x, y;

int exgcd(int a, int b){
    if(b==0){
        x=1, y=0;
        return a;
    }
    int c=exgcd(b, a%b);
    int d=x;
    x=y, y=d-a/b*y;
    return c;
}

int main(){
    exgcd(1,2);
    return 0;
}