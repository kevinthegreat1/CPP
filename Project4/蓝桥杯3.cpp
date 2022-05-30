#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k, r, s, c, i, score=0;
    string t, a;
    cin>>n>>k;
    cin>>r>>s>>c;
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    for(i=0;i<n;i++){
        if(t[i]=='r'){
            if(a[i-k]=='c'){
                a[i]='r';
            } else {
                a[i]='c';
                score+=c;
            }
        } else if(t[i]=='s'){
            if(a[i-k]=='r'){
                a[i]='s';
            } else {
                a[i]='r';
                score+=r;
            }
        } else if(t[i]=='c'){
            if(a[i-k]=='s'){
                a[i]='c';
            } else {
                a[i]='s';
                score+=s;
            }
        }
    }
    cout<<score;
    return 0;
}