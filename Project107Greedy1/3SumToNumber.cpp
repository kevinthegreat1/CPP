//
// Created by Kevin Yang on 4/10/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target, total = 0, longest = 0, i, j;
    cin >> n;
    vector<int> nums(n);
    for (i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }
    cin >> target;
    if (nums[0] > target && nums[n - 1] > target) {
        cout << -1;
        return 0;
    }
    bool flag = false;
    vector <vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + nums[j - 1];
            if (total - dp[i][j] == target) {
                longest = max(j - i + 1, longest);
                flag = true;
            }
        }
    }
    if (flag) {
        cout << n - longest;
    } else {
        cout << -1;
    }
    return 0;
}