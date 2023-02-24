//
// Created by Kevin Yang on 2/19/23.
//

#include <iostream>

using namespace std;

const int N = 101;

int main() {
    int n, W;
    cin >> n >> W;
    int v[n], w[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    int dp[N][N];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= W; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j >= w[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][W] << endl;
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            cout << i << " ";
            j -= w[--i];
        }
    }
    return 0;
}