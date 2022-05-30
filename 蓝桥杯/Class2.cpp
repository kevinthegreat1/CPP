#include <iostream>

using namespace std;

int main(){
    int i, dots=0;
    string input;
    cin>>input;
    for(i=0;i<input.size();i++){
        if(input[i]=='.'){
            dots++;
        }
    }
    cout<<input.size()<<endl<<dots;
    return 0;
}