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
    int dp[N];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j >= w[i - 1]) {
                dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << dp[W] << endl;
    return 0;
}