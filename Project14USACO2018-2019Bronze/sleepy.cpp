#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int n, i, j;
    vector<int> cows;
    fin>>n;
    for(i=0;i<n;i++){
        fin>>j;
        cows.push_back(j);
    }
    fin.close();
    for(i=0;;i++){
        for(j=1;j<n;j++){
            if(cows[j-1]>cows[j]){
                break;
            }
            if(j==n-1){
                fout<<i;
                fout.close();
                return 0;
            }
        }
        for(j=n-1;j>0;j--){
            if(cows[0]>cows[j]){
                cows.insert(cows.begin()+j+1, cows[0]);
                cows.erase(cows.begin());
                break;
            }
            if(cows[j-1]>cows[j]){
                cows.insert(cows.begin()+j, cows[0]);
                cows.erase(cows.begin());
                break;
            }
        }
    }
}