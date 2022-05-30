//
// Created by Kevin Yang on 6/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size(), most = 0, i, j;
        vector<int> dp(n, 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            most = max(dp[i], most);
        }
        return most;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums);
    return 0;
}