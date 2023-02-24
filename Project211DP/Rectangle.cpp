//
// Created by Kevin Yang on 2/23/23.
//

#include <iostream>

using namespace std;

const int N = 101;
int a[N][N];

int main() {
    int n;
    cin >> n;
    int dp[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    dp[n - 1][0] = a[n - 1][0];
    int x = n - 1, y = 0;
    while (x != 0 || y != n - 1) {
        if (y == n - 1) {
            x--;
        } else {
            y++;
        }
        int i = x, j = y;
        while (i >= 0 && j >= 0) {
            if (i == n - 1) {
                dp[i][j] = dp[i][j - 1] + a[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i + 1][j] + a[i][j];
            } else {
                dp[i][j] = max(max(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]) + a[i][j];
            }
            i--;
            j--;
        }
    }
    cout << dp[0][n - 1];
    return 0;
}