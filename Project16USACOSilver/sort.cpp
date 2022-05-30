#include <iostream>

using namespace std;

bool comp(int a, int b){return a>b;}

int main(){
    int a[]{1,4,15,6,25,16,3,14,12,45,13,65,17,24,54,22,15,21,75,2};
    sort(a,a+20,comp);
    for(int i=0;i<20;i++){
        cout<<a[i]<<", ";
    }
    return 0;
}