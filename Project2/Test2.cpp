/*
ID: your_id_here
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    int i, ans1=1,ans2=1;
    string a, b;
    fin >> a >> b;
    for(i=0;i<a.length();i++){
        ans1*=a[i]-'@';
        ans1%=47;
    }
    for(i=0;i<b.length();i++){
        ans2*=b[i]-'@';
        ans2%=47;
    }
    ans1==ans2?fout << "GO" << endl:fout << "STAY" << endl;
    return 0;
}