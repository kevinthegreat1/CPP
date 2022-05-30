//
// Created by Kevin Yang on 6/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a[0] > b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size(), most = 0, i, j;
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp(n + 1, 1);
        for (i = 1; i <= n; i++) {
            for (j = 1, 0; j < i; j++) {
                if (envelopes[j - 1][0] > envelopes[i - 1][0] && envelopes[j - 1][1] > envelopes[i - 1][1]) {
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
    vector<vector<int>> envelopes = {{5, 4},
                                     {6, 4},
                                     {6, 7},
                                     {2, 3}};
    cout << solution.maxEnvelopes(envelopes);
    return 0;
}