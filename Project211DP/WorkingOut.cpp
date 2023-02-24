//
// Created by Kevin Yang on 2/23/23.
//

#include <iostream>

using namespace std;

const int N = 101;

int gain[N][N];
int n, m;
int dpTopLeft[N][N], dpTopRight[N][N], dpBottomLeft[N][N], dpBottomRight[N][N];

int solve(int dp[N][N], int startRow, int startCol, int endRow, int endCol, int incrementRow, int incrementCol) {
    dp[startRow][startCol] = gain[startRow][startCol];
    int x = startRow, y = startCol;
    while (x != endRow || y != endCol) {
        if (y == endCol) {
            x += incrementRow;
        } else {
            y += incrementCol;
        }
        int i = x, j = y;
        while (i >= 0 && i < n && j >= 0 && j < m) {
            int incrementedI = i - incrementRow;
            int incrementedJ = j - incrementCol;
            if (incrementedI < 0 || incrementedI >= n) {
                dp[i][j] = dp[i][j - incrementCol] + gain[i][j];
            } else if (incrementedJ < 0 || incrementedJ >= n) {
                dp[i][j] = dp[i - incrementRow][j] + gain[i][j];
            } else {
                dp[i][j] = max(max(dp[i - incrementRow][j], dp[i][j - incrementCol]),
                               dp[i - incrementRow][j - incrementCol]) + gain[i][j];
            }
            i += incrementRow;
            j -= incrementCol;
        }
    }
    return dp[endRow][endCol];
}

int getGainAt(int row, int col) {
    return dpTopLeft[row][col] + dpTopRight[row][col] + dpBottomLeft[row][col] + dpBottomRight[row][col] -
           4 * gain[row][col];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gain[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dpTopLeft[i][j] = 0;
            dpTopRight[i][j] = 0;
            dpBottomLeft[i][j] = 0;
            dpBottomRight[i][j] = 0;
        }
    }
    solve(dpTopLeft, 0, 0, n - 1, m - 1, 1, 1);
    solve(dpTopRight, 0, m - 1, n - 1, 0, 1, -1);
    solve(dpBottomLeft, n - 1, 0, 0, m - 1, -1, 1);
    solve(dpBottomRight, n - 1, m - 1, 0, 0, -1, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, getGainAt(i, j));
        }
    }
    cout << ans;
    return 0;
}