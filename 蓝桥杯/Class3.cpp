#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int input[6], i;
    for(i=0;i<5;i++){
        cin>>input[i];
    }
    sort(input,input+5);
    reverse(input,input+5);
    for(i=0;i<5;i++){
        cout<<input[i];
        if(i!=4){
            cout<<",";
        }
    }
    return 0;
}