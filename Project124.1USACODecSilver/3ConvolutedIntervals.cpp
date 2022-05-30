//
// Created by Kevin Yang on 12/19/21.
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
    map<int, vector<pair<int, int>>> min, max;
    for (i = 0; i <= 2 * m; i++) {
        min[i] = vector<pair<int, int>>{};
        max[i] = vector<pair<int, int>>{};
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            min[intervals[i].first + intervals[j].first].emplace_back(i, j);
            max[intervals[i].second + intervals[j].second].emplace_back(i, j);
            min[intervals[j].first + intervals[i].first].emplace_back(j, i);
            max[intervals[j].second + intervals[i].second].emplace_back(j, i);
        }
    }
    set<pair<int, int>> cur;
    for (i = 0; i <= 2 * m; i++) {
        cur.insert(min.at(i).begin(), min.at(i).end());
        cout << cur.size() << endl;
        for (auto t: max.at(i)) {
            cur.erase(t);
        }
    }
    return 0;
}