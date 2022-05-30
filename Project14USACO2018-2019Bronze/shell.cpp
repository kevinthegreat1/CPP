#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n, a, b, g, i, shell[2][4];
    fin>>n;
    for(i=1;i<4;i++){
        shell[0][i]=i;
        shell[1][i]=0;
    }
    for(i=0;i<n;i++){
        fin>>a>>b>>g;
        swap(shell[0][a], shell[0][b]);
        shell[1][shell[0][g]]++;
    }
    for(i=1,n=0;i<4;i++){
        n=max(shell[1][i], n);
    }
    fout<<n;
    fin.close();
    fout.close();
    return 0;
}