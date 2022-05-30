#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, largest=0, i, j, k;
    cin >> n;
    int cows[51][4];
    char s;
    for (i = 1; i <= n; i++) {
        cin >> s >> cows[i][1] >> cows[i][2];
        if (s == 'E') {
            cows[i][0] = 1;
        } else {
            cows[i][0] = 2;
        }
        cows[i][3] = 0;
        largest = max(max(cows[i][1], cows[i][2]), largest);
    }
    bool grass[12][12];
    for(i=0;i<=largest;i++){
        for(j=0;j<=largest;j++){
            grass[i][j]=false;
        }
    }
    for(i=0;i<=largest;i++){
        for(j=1;j<=n;j++){
            if(cows[j][0]!=0) {
                grass[cows[j][1]][cows[j][2]]=true;
                cows[j][cows[j][0]]++;
                cows[j][3]++;
            }
            if(cows[j][1]<largest+1 && cows[j][2]<largest+1) {
                if (grass[cows[j][1]][cows[j][2]] && cows[j][0] != 0) {
                    cows[j][0] = 0;
                }
            }
        }
    }
    for (j = 1; j <= n; j++) {
        if (cows[j][0]==0) {
            cout << cows[j][3];
        } else {
            cout << "Infinity";
        }
        if (j != n) {
            cout << endl;
        }
    }
    return 0;
}