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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    int dp[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans;
    return 0;
}