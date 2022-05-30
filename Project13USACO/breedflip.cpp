#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    bool flip=false;
    int i, count=0;
    string breed, target;
    fin>>i>>target>>breed;
    for(i=0;i<target.length();i++){
        if(flip==false && breed[i]!=target[i]){
            flip=true;
        } else if(flip==true && breed[i]==target[i]){
            count++;
            flip=false;
        }
    }
    fout<<count;
    return 0;
}