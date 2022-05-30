//
// Created by Kevin Yang on 3/20/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        int i = 0;
        while (dp[k][i] < n) {
            i++;
            for (int j = 1; j <= k; j++) {
                dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1] + 1;
            }
        }
        return i;
    }
};

int main() {
    Solution solution;
    cout << solution.superEggDrop(1, 2) << endl;
    cout << solution.superEggDrop(2, 6) << endl;
    cout << solution.superEggDrop(3, 14) << endl;
    cout << solution.superEggDrop(1000, 100000) << endl;
    return 0;
}