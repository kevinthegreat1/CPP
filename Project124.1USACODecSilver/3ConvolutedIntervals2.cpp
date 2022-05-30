//
// Created by Kevin Yang on 12/27/21.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m, i, j;
    cin >> n >> m;
    vector<pair<int, int>> intervals;
    for (i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        intervals.emplace_back(t1, t2);
    }
    vector<int> min(2 * m + 1), max(2 * m + 1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            min[intervals[i].first + intervals[j].first]++;
            max[intervals[i].second + intervals[j].second]++;
        }
    }
    int cur = 0;
    for (i = 0; i <= 2 * m; i++) {
        cur += min[i];
        cout << cur << endl;
        cur -= max[i];
    }
    return 0;
}