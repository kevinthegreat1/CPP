#include <iostream>
#include <queue>

using namespace std;

struct node{
    int a, b;
};

int main(){
    queue<node> a;
    node b={21,23};
    a.push(b);
    cout<<a.front().a<<", "<<a.front().b<<endl;
    a.pop();
    return 0;
}