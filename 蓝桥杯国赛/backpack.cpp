//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, i, j;
    cin >> n >> m;
    int items[m + 1][2];
    for (i = 1; i <= m; i++) {
        cin >> items[i][0] >> items[i][1];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (items[i][0] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i][j - items[i][0]] + items[i][1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[m][n];
    return 0;
}