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
    vector<long long> min(2 * m + 1), max(2 * m + 1);
    vector<long long> countMin(m + 1), countMax(m + 1);
    for (i = 0; i < n; i++) {
        countMin[intervals[i].first]++;
        countMax[intervals[i].second]++;
    }
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= m; j++) {
            min[i + j] += countMin[i] * countMin[j];
            max[i + j] += countMax[i] * countMax[j];
        }
    }
    long long cur = 0;
    for (i = 0; i <= 2 * m; i++) {
        cur += min[i];
        cout << cur << endl;
        cur -= max[i];
    }
    return 0;
}