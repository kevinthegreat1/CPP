//
// Created by Kevin Yang on 5/15/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int weight, volume, n, i, j, k;
    cin >> weight >> volume >> n;
    vector<vector<int>> items(n + 1, vector<int>(3));
    for (i = 1; i <= n; i++) {
        cin >> items[i][0] >> items[i][1] >> items[i][2];
    }
    vector<vector<vector<pair<int, vector<int>>>>> dp(n + 1, vector<vector<pair<int, vector<int>>>>(weight + 1,
                                                                                                    vector<pair<int, vector<int>>>(
                                                                                                            volume + 1,
                                                                                                            pair<int, vector<int>>(
                                                                                                                    0,
                                                                                                                    vector<int>()))));
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= weight; j++) {
            for (k = 0; k <= volume; k++) {
                if (items[i][0] > j || items[i][1] > k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                } else {
                    if (dp[i - 1][j - items[i][0]][k - items[i][1]].first + items[i][2] > dp[i - 1][j][k].first) {
                        dp[i][j][k].first = dp[i - 1][j - items[i][0]][k - items[i][1]].first + items[i][2];
                        dp[i][j][k].second = dp[i - 1][j - items[i][0]][k - items[i][1]].second;
                        dp[i][j][k].second.push_back(i);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
//                    dp[i][j][k].first = max(dp[i - 1][j - items[i][0]][k - items[i][1]].first + items[i][2], dp[i - 1][j][k].first);
                }
            }
        }
    }
    cout << dp[n][weight][volume].first << endl;
    for (i = 0; i < dp[n][weight][volume].second.size(); i++) {
        cout << dp[n][weight][volume].second[i];
        if (i < dp[n][weight][volume].second.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}