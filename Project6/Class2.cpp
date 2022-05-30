#include <iostream>

using namespace std;

unsigned int fib(unsigned int n){
    if(n<3){
        return 1;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

int main(){
    cout<<fib(1)<<endl;
    cout<<fib(2)<<endl;
    cout<<fib(3)<<endl;
    cout<<fib(4)<<endl;
    cout<<fib(5)<<endl;
    cout<<fib(6)<<endl;
    cout<<fib(7)<<endl;
    cout<<fib(8)<<endl;
    cout<<fib(9)<<endl;
}