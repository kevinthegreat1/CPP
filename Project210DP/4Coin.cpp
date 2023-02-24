//
// Created by Kevin Yang on 2/19/23.
//

#include <iostream>

using namespace std;

const int N = 101;

int main() {
    int n, a;
    cin >> n;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cin >> a;
    int dp[N];
    dp[0] = 0;
    for (int i = 0; i <= a; i++) {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a; j++) {
            if (j >= c[i - 1]) {
                dp[j] = min(dp[j], dp[j - c[i - 1]] + 1);
            }
        }
    }
    cout << dp[a] << endl;
    return 0;
}