//
// Created by Kevin Yang on 5/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, most = 0, largest, i, j;
    cin >> n;
    vector<int> hoops(n + 1);
    for (i = 1; i <= n; i++) {
        cin >> hoops[i];
    }
    vector<pair<int, int>> dp(n + 1, pair<int, int>(0, 0));
    for (i = 1; i <= n; i++) {
        for (j = 1, largest = 0; j < i; j++) {
            if (dp[j].second > hoops[i] && dp[j].first > dp[largest].first) {
                largest = j;
            }
        }
        dp[i].first = dp[largest].first + 1;
        dp[i].second = hoops[i];
        most = max(dp[i].first, most);
    }
    cout << most;
    return 0;
}