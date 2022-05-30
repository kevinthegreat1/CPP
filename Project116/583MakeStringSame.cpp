//
// Created by Kevin Yang on 7/3/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(), i, j;
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n-dp[n][m]+m-dp[n][m];
    }
};

int main(){
    Solution solution;
    cout << solution.minDistance("sea","eat");
    return 0;
}