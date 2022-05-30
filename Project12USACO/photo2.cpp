#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    int n, i, j;
    fin>>n;
    int b[n-1], a[n];
    for(i=0;i<n-1;i++){
        fin>>b[i];
    }
    fin.close();
    bool flag[n+1];
        for (i = 1; i <= b[0] && i <= n; i++) {
            a[0] = i;
            for (j = 1; j <= n; j++) {
                flag[j] = false;
            }
            flag[a[0]] = true;
            for (j = 0; j < n - 1; j++) {
                a[j + 1] = b[j] - a[j];
                if (a[j+1] > n) {
                    break;
                } else if (flag[a[j+1]]) {
                    break;
                } else {
                    flag[a[j+1]] = true;
                }
                if (j == n - 2) {
                    for (i = 0; i < n; i++) {
                        fout<<a[i];
                        if (i != n - 1) {
                            fout<<" ";
                        }
                    }
                    fout.close();
                    return 0;
            }
        }
    }
    return 0;
}