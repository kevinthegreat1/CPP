#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int direction=0, x_coordinate=1, y_coordinate=2, traveled=3, E=1, N=2;
    int n, largest = 0, distance1, distance2, i, j, k;
    cin >> n;
    int cows[51][4];
    char s;
    for (i = 1; i <= n; i++) {
        cin >> s >> cows[i][x_coordinate] >> cows[i][y_coordinate];
        if (s == 'E') {
            cows[i][direction] = E;
        } else {
            cows[i][direction] = N;
        }
        cows[i][traveled] = 2000000000;
        largest=max(max(cows[i][x_coordinate], cows[i][y_coordinate]), largest);
    }
    for (i = 1; i <= largest; i++) {
        for (j = 1; j <= n; j++) {
            for (k = j + 1; k <= n; k++) {
                if (abs(cows[k][x_coordinate] - cows[j][x_coordinate]) == i || abs(cows[k][y_coordinate] - cows[j][y_coordinate]) == i) {
                    distance1 = cows[k][cows[j][direction]] - cows[j][cows[j][direction]];
                    distance2 = cows[j][cows[k][direction]] - cows[k][cows[k][direction]];
                    if (cows[j][direction] != cows[k][direction] && distance1 > 0 && distance2 > 0 && distance1 < cows[j][3] &&
                        distance2 < cows[k][traveled]) {
                        if (distance1 > distance2) {
                            cows[j][traveled] = min(distance1, cows[j][traveled]);
                        } else if (distance2 > distance1) {
                            cows[k][traveled] = min(distance2, cows[k][traveled]);
                        }
                    }
                }
            }
        }
    }
    for (j = 1; j <= n; j++) {
        if (cows[j][traveled] < 2000000000) {
            cout << cows[j][traveled];
        } else {
            cout << "Infinity";
        }
        if (j != n) {
            cout << endl;
        }
    }
    return 0;
}