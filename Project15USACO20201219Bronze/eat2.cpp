#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, largest, distance1, distance2, i, j, k;
    cin >> n;
    int cows[51][5];
    char s;
    for (i = 1; i <= n; i++) {
        cin >> s >> cows[i][1] >> cows[i][2];
        if (s == 'E') {
            cows[i][0] = 1;
        } else {
            cows[i][0] = 2;
        }
        cows[i][3] = 2000000000;
        cows[i][4] = 2000000000;
    }
    for (i = 1; i <= n; i++) {
        largest = max(max(cows[i][1], cows[i][2]), largest);
    }
    for (j = 1; j <= n; j++) {
        for (k = j + 1; k <= n; k++) {
            if (abs(cows[k][1] - cows[j][1]) == i || abs(cows[k][2] - cows[j][2]) == i) {
                distance1 = cows[k][cows[j][0]] - cows[j][cows[j][0]];
                distance2 = cows[j][cows[k][0]] - cows[k][cows[k][0]];
                if (cows[j][0] != cows[k][0] && distance1 > 0 && distance2 > 0 && distance1 < cows[j][3] &&
                    distance2 < cows[k][3]) {
                    if (distance1 > distance2) {
                        cows[j][3] = min(distance1, cows[j][3]);
                    } else if (distance2 > distance1) {
                        cows[k][3] = min(distance2, cows[k][3]);
                    }
                }
            }
        }
    }
    for (j = 1; j <= n; j++) {
        for (k = 1; k <= n; k++) {
            if(cows[k][3]==j){
                break;
            }
        }
        for (k = 1; k <= n; k++) {
            if (abs(cows[k][1] - cows[j][1]) == i || abs(cows[k][2] - cows[j][2]) == i) {
                distance1 = cows[k][cows[j][0]] - cows[j][cows[j][0]];
                distance2 = cows[j][cows[k][0]] - cows[k][cows[k][0]];
                if (cows[j][0] != cows[k][0] && distance1 > 0 && distance2 > 0 && distance1 < cows[j][3] &&
                    distance2 < cows[k][3]) {
                    if (distance1 > distance2) {
                        cows[j][4] = min(distance1, cows[j][4]);
                    } else if (distance2 > distance1) {
                        cows[k][4] = min(distance2, cows[k][4]);
                    }
                }
            }
        }
    }
    for (j = 1; j <= n; j++) {
        if (cows[j][4] < 2000000000) {
            cout << cows[j][4];
        } else {
            cout << "Infinity";
        }
        if (j != n) {
            cout << endl;
        }
    }
    return 0;
}