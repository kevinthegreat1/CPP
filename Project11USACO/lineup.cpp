#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    bool flag=false;
    int i, j, k, n;
    fin>>n;
    string name[]={ "Belinda","Sue","Bessie","Blue","Betsy","Buttercup","Beatrice","Bella"}, rule[2][n], a;
    sort(name,name+8);
    for(i=0;i<n;i++){
        fin>>rule[0][i]>>a>>a>>a>>a>>rule[1][i];
    }
    for(i=0;i<40320;i++){
        for(j=0;j<n;j++){
            for(k=1;k<7;k++){
                if(name[k]==rule[0][j] && (name[k+1]==rule[1][j] || name[k-1]==rule[1][j])){
                    break;
                } else if(name[k]==rule[1][j] && (name[k+1]==rule[0][j] || name[k-1]==rule[0][j])){
                    break;
                } else if(k==6){
                    flag=true;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            for(j=0;j<8;j++){
                fout<<name[j]<<endl;
            }
            return 0;
        }
        next_permutation(name,name+8);
        flag=false;
    }
    return 0;
}