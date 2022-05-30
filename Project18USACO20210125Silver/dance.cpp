#include <iostream>

using namespace std;

int main() {
    int n, k, ans, i, j;
    cin >> n >> k;
    int move1[k], move2[k], cows[n + 1];
    for (i = 0; i < k; i++) {
        cin >> move1[i] >> move2[i];
    }
    bool flag, visited[2040][2040]{false};
    for (i = 0; i <= n; i++) {
        cows[i] = i;
        visited[i][i] = true;
    }
    for (i = 0;; i++, i %= k) {
        swap(cows[move1[i]], cows[move2[i]]);
        visited[cows[move1[i]]][move2[i]] = true;
        visited[cows[move2[i]]][move1[i]] = true;
        for (j = 1, flag = false; j <= n && !flag; j++) {
            if (cows[j] != j) {
                flag = true;
            } else if (j == n) {
                for (i = 1; i <= n; i++) {
                    for (j = 1, ans = 0; j <= n; j++) {
                        ans += visited[i][j];
                    }
                    cout << ans << endl;
                }
                return 0;
            }
        }
    }
}