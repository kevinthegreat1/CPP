#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    int n, i;
    fin>>n;
    int b[n-1], a[n];
    for(i=0;i<n-1;i++){
        fin>>b[i];
    }
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
    while(true){
        bool flag=false;
        for(i=0;i<n-1;i++){
            if(a[i]+a[i+1]!=b[i]){
                flag=true;
            }
        }
        if(!flag){
            break;
        }
        next_permutation(a,a+n);
    }
    for(i=0;i<n;i++){
        fout<<a[i];
        if(i!=n-1){
            fout<<" ";
        }
    }
    fin.close();
    fout.close();
    return 0;
}