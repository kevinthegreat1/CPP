#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool outcomes[1500];

void bucket(int day, int milk, vector<int> a, vector<int> b){
    if(day==5){
        outcomes[milk]=true;
        return;
    }
    int i;
    if(day%2==1){
        for(i=0;i<a.size();i++){
            vector<int> a2=a;
            vector<int> b2=b;
            a2.erase(a2.begin()+i);
            b2.push_back(a[i]);
            bucket(day+1, milk-a[i], a2, b2);
        }
    } else {
        for(i=0;i<b.size();i++){
            vector<int> a2=a;
            vector<int> b2=b;
            a2.push_back(b[i]);
            b2.erase(b2.begin()+i);
            bucket(day+1, milk+b[i], a2, b2);
        }
    }
}

int main(){
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    int ans=0, n, i;
    vector<int> a, b;
    for(i=0;i<10;i++){
        fin>>n;
        a.push_back(n);
    }
    for(i=0;i<10;i++){
        fin>>n;
        b.push_back(n);
    }
    bucket(1, 1000, a, b);
    for(i=0;i<2000;i++){
        ans+=outcomes[i];
    }
    fout<<ans;
    fin.close();
    fout.close();
    return 0;
}