/*
Q1: 有n个特殊点(1~n)和m个普通点(n+1~n+m)，每个地方都可以进行一次标记，它们之间有一些边，这些边保证让所有特殊点都至少和一个带标记的点是连通的。标记和新建一条边是有代价的，让你来新建标记和边，求最小的费用。
(1<=n<=5, 0<=m<=1000, 0<=p<=5000)

Sample:
Input:
n m p
a[1] a[2] a[3] ...  a[n+m]表示每个点标记的费用
接下来p行每行a b c表示a到b之间的连边需要花费c
3 1 4
1 2 3 4
1 4 2
2 4 2
3 4 4
4 1 4
Output:
6

Input:
4 1 4
5 5 5 5 1
1 5 1
2 5 1
3 5 1
4 5 1
Output:
5
*/

#include <iostream>
#include <map>

using namespace std;

int dpStateCompression(int n, int m, map<int, int> edges[]) {
    int dp[1006][(1 << 5) - 1];
    for (int i = 0; i <= n + m; i++) {
        dp[i][0] = 0;
        for (int j = 1; j < 1 << n; j++) {
            dp[i][j] = -1;
        }
        for (int j = 0; j <= n; j++) {
            int cost = i <= j + 1 ? edges[i][j + 1] : edges[j + 1][i];
            if (cost != 0) {
                dp[i][1 << j] = cost;
            }
        }
        if (i > 0 && i <= n) {
            dp[i][1 << (i - 1)] = 0;
        }
    }
    for (int i = n + m; i >= 0; i--) {
        for (int j = 1; j < 1 << n; j++) {
            for (int k = 0; k <= n + m; k++) {
                int cost = i <= k ? edges[i][k] : edges[k][i];
                if (cost != 0 && dp[k][j] >= 0) {
                    if (dp[i][j] >= 0) {
                        dp[i][j] = min(dp[k][j] + cost, dp[i][j]);
                    } else {
                        dp[i][j] = dp[k][j] + cost;
                    }
                }
            }
            for (int k = 0; k < j; k++) {
                if ((k | j) == j && dp[i][k] >= 0 && dp[i][j ^ k] >= 0) {
                    if (dp[i][j] >= 0) {
                        dp[i][j] = min(dp[i][k] + dp[i][j ^ k], dp[i][j]);
                    } else {
                        dp[i][j] = dp[i][k] + dp[i][j ^ k];
                    }
                }
            }
        }
    }
    return dp[0][(1 << n) - 1];
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    map<int, int> edges[n + m + 1];
    for (int i = 1; i <= n + m; i++) {
        int cost;
        cin >> cost;
        edges[0][i] = cost;
    }
    for (int i = 0; i < p; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (from > to) { swap(from, to); }
        edges[from][to] = edges[from][to] ? min(edges[from][to], cost) : cost;
    }
    cout << dpStateCompression(n, m, edges) << endl;
    return 0;
}
