/*
ID: your_id_here
TASK: gymnastics
LANG: C++                 
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int m, n, i, j, k, ans=0;
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    fin>>m>>n;
    int input[n];
    bool output[n][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            fin>>input[j];
        }
        for(j=0;j<n-1;j++){
            for(k=j+1;k<n;k++){
                output[input[j]-1][input[k]-1]=true;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(output[i][j]!=output[j][i]){
                ans++;
            }
        }
    }
    fout<<ans;
    return 0;
}