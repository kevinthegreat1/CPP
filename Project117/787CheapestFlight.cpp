//
// Created by Kevin Yang on 7/18/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        int answer = INT16_MAX, i, j, l;
        vector<vector<int>> dp(k + 2, vector<int>(n, INT16_MAX));
        dp[0][src] = 0;
        for (i = 1; i <= k + 1; i++) {
            for (j = 0; j < n; j++) {
                for (l = 0; l < flights.size(); l++) {
                    if (flights[l][1] == j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][flights[l][0]] + flights[l][2]);
                    }
                }
            }
        }
        for (i = 0; i <= k + 1; i++) {
            answer = min(dp[i][dst], answer);
        }
        if (answer == INT16_MAX) {
            return -1;
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> flights = {{0, 1, 100},
                                   {1, 2, 100},
                                   {0, 2, 500}};
    cout << solution.findCheapestPrice(3, flights, 0, 2, 1);
    return 0;
}