//
// Created by Kevin Yang on 4/24/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i, j, k;
    cin >> n;
    vector<int> nums(n);
    for (i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    vector<int> dp(n, INT32_MIN);
    dp[0] = nums[0];
    for (i = 1; i < n; i++) {
        for (j = 1; j <= k && i - j >= 0; j++) {
            dp[i] = max(dp[i - j] + nums[i], dp[i]);
        }
    }
    cout << dp[n - 1];
    return 0;
}