//
// Created by Kevin Yang on 3/23/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j;
        if (p == s) {
            return true;
        }
        if (p.empty()) {
            return false;
        }
        for (i = 0; i < p.size(); i++) {
            if (p[i] == '?' || p[i] == '*') {
                break;
            }
        }
        if (i == p.size()) {
            return false;
        }
        vector <vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = true;
        for (i = 0; i < p.size(); i++) {
            if (p[i] == '*') {
                dp[0][i + 1] = true;
            } else {
                break;
            }
        }
        for (i = 0; i < s.size(); i++) {
            for (j = 0; j < p.size(); j++) {
                if (p[j] == s[i] || p[j] == '?') {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    Solution solution;
    cout << solution.isMatch(s, p);
    return 0;
}