//
// Created by Kevin Yang on 4/10/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int> &groups) {
        int answer = 0;
        for (auto group = groups.begin(); group != groups.end();) {
            *group = *group % batchSize;
            if (*group == 0) {
                answer++;
                groups.erase(group);
            } else {
                group++;
            }
        }
        sort(groups.begin(), groups.end());
        for (auto group = groups.begin(); group != groups.end();) {
            auto it = find(group + 1, groups.end(), batchSize - *group);
            if (it != groups.end()) {
                groups.erase(group);
                groups.erase(--it);
                answer++;
            } else {
                group++;
            }
        }
        vector<int> count(9, 0);
        for (int group: groups) {
            count[group]++;
        }
        int dp[count[1] + 1][
                count[2] + 1][count[3] + 1][count[4] + 1][count[5] + 1][count[6] + 1][count[7] + 1][count[8] + 1];
        for (int i = 0; i <= count[1]; i++) {
            for (int j = 0; j <= count[2]; j++) {
                for (int k = 0; k <= count[3]; k++) {
                    for (int l = 0; l <= count[4]; l++) {
                        for (int m = 0; m <= count[5]; m++) {
                            for (int n = 0; n <= count[6]; n++) {
                                for (int o = 0; o <= count[7]; o++) {
                                    for (int p = 0; p <= count[8]; p++) {
                                        dp[i][j][k][l][m][n][o][p] = 0;
                                        int sum = i + j * 2 + k * 3 + l * 4 + m * 5 + n * 6 + o * 7 + p * 8;
                                        if (i > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i - 1][j][k][l][m][n][o][p] +
                                                                             ((sum - 1) % batchSize == 0));
                                        }
                                        if (j > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j - 1][k][l][m][n][o][p] +
                                                                             ((sum - 2) % batchSize == 0));
                                        }
                                        if (k > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j][k - 1][l][m][n][o][p] +
                                                                             ((sum - 3) % batchSize == 0));
                                        }
                                        if (l > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j][k][l - 1][m][n][o][p] +
                                                                             ((sum - 4) % batchSize == 0));
                                        }
                                        if (m > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j][k][l][m - 1][n][o][p] +
                                                                             ((sum - 5) % batchSize == 0));
                                        }
                                        if (n > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j][k][l][m][n - 1][o][p] +
                                                                             ((sum - 6) % batchSize == 0));
                                        }
                                        if (o > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j][k][l][m][n][o - 1][p] +
                                                                             ((sum - 7) % batchSize == 0));
                                        }
                                        if (p > 0) {
                                            dp[i][j][k][l][m][n][o][p] = max(dp[i][j][k][l][m][n][o][p],
                                                                             dp[i][j][k][l][m][n][o][p - 1] +
                                                                             ((sum - 8) % batchSize == 0));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return answer + dp[count[1]][count[2]][count[3]][count[4]][count[5]][count[6]][count[7]][count[8]];
    }
};

int main() {
    Solution solution;
    vector<int> groups1 = {1, 2, 3, 4, 5, 6};
    vector<int> groups2 = {1, 3, 2, 5, 2, 2, 1, 6};
    vector<int> groups3 = {652231582, 818492002, 823729239, 2261354, 747144855, 478230860, 285970257, 774747712,
                           860954510, 245631565, 634746161, 109765576, 967900367, 340837477, 32845752, 23968185};
    vector<int> groups4 = {287773481, 815094798, 356732984, 644469322, 543193620, 903158817, 274116865, 395252956,
                           363839119, 365378492, 122313059, 312690039, 252532812};
    cout << solution.maxHappyGroups(7, groups4);
    return 0;
}