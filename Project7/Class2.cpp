#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string a;
    cin>>a;
    stack<char> b;
    for(int i=0;i<a.size();i++){
        if(a[i]!='#'){
            b.push(a[i]);
        } else {
            b.pop();
        }
    }
    stack<char> c;
    for(int i=0;!b.empty();i++){
        c.push(b.top());
        b.pop();
    }
    for(int i=0;!c.empty();i++){
        cout<<c.top();
        c.pop();
    }
    cout<<endl;
    return 0;
}