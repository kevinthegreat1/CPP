/*
ID: your_id_here
TASK: whereami
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    int length, i, j, k;
    string input;
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    fin>>length>>input;
    for(i=1;i<length;i++){
        bool b=false;
        for(j=0;j<=length-i;j++){
            string a = input.substr(j,i);
            for(k=0;k<=length-i;k++){
                if(k!=j && input.substr(k,i)==a){
                    b=true;
                }
            }
            if(b){
                break;
            }
        }
        if(!b){
            fout<<i;
            return 0;
        } else if(i==length-1){
            fout<<i+1;
            return 0;
        }
    }
    return 0;
}