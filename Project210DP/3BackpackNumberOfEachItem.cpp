//
// Created by Kevin Yang on 2/19/23.
//

#include <iostream>
#include <vector>

using namespace std;

const int N = 101;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v, w;
    int m[n];
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight >> m[i];
        int j = 1;
        while (m[i] > j) {
            v.push_back(value * j);
            w.push_back(weight * j);
            j *= 2;
        }
    }
    int dp[N][N];
    for (int i = 0; i <= v.size(); i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= W; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= v.size(); i++) {
        for (int j = 1; j <= W; j++) {
            if (j >= w[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[v.size()][W] << endl;
    return 0;
}