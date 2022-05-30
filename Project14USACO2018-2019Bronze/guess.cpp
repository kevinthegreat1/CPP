#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin("/Users/kevinyang/Documents/Learning/Coding/C++/Project14USACO2018-2019/guess.in");
    ofstream fout("/Users/kevinyang/Documents/Learning/Coding/C++/Project14USACO2018-2019/guess.out");
    int n, m, largest=0, count;
    string s;
    vector<string> characteristics[100];
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>s>>m;
        for(int j=0;j<m;j++){
            fin>>s;
            characteristics[i].push_back(s);
        }
    }
    fin.close();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            count=0;
            for(int k=0;k<characteristics[i].size();k++){
                for(int l=0;l<characteristics[j].size();l++){
                    if(characteristics[i][k]==characteristics[j][l]){
                        count++;
                    }
                }
            }
            largest=max(count,largest);
        }
    }
    fout<<largest+1;
    fout.close();
    return 0;
}