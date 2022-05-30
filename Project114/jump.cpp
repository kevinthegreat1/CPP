//
// Created by Kevin Yang on 5/28/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, p, l, sum, i = 0, j, t;
    cin >> k >> p >> l;
    vector<vector<int>> dp(l + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (i = 1; i <= l; i++) {
        sum = 0;
        for (j = 1; j < p && i-j>=0; j++) {
            sum += dp[(i - j)][1] % 20201114;
        }
        dp[i][0] = sum;
        for (j = p; j <= k && i-j>=0; j++) {
            sum += dp[(i - j)][0] % 20201114;
        }
        dp[i][1] = sum;
    }
    cout << ((dp[i-1][1]) % 20201114);
    return 0;
}