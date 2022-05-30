//
// Created by Kevin Yang on 3/28/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    bool t;
    int n, m, answer = 0, i, j, k;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(m));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> t;
            board[i][j] = t;
        }
    }
    vector<vector<int>> height(n + 1, vector<int>(m + 1, 0));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
//    int count;
//    for (i = 1; i <= m; i++) {
//        !board[0][i - 1] ?: height[1][i] = 1;
//    }
//    for(i=1;i<=n;i++) {
//        !board[i - 1][0] ?: height[i][1] = height[i - 1][1] + 1;
//    }
//    for (i = 1; i <= n; i++) {
//        for (j = 1; j <= height[i][1]; j++) {
//            dp[i][1][j] = j;
//        }
//    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (board[i - 1][j - 1] == 0) {
                continue;
            }
            height[i][j] = height[i - 1][j] + 1;
            for (k = 1; k <= height[i][j]; k++) {
                dp[i][j][k] = dp[i][j - 1][k] + k;
//                answer=max(dp[i][j][j],answer);
                dp[i][j][k] <= answer ?: answer = dp[i][j][k];
            }
        }
    }
    cout << answer;
    return 0;
}