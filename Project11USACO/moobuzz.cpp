#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    int n;
    fin>>n;
    int round=floor((n-1)/8)*15+1;
    n=n%8;
    if(n==1){
        fout<<round;
    } else if(n==2){
        fout<<round+1;
    } else if(n==3){
        fout<<round+3;
    } else if(n==4){
        fout<<round+6;
    } else if(n==5){
        fout<<round+7;
    } else if(n==6){
        fout<<round+10;
    } else if(n==7){
        fout<<round+12;
    } else if(n==0){
        fout<<round+13;
    }
    return 0;
}

// num, num, a, num, a, a, num, num, a, a, num, a, num, num, a